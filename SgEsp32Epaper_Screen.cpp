#include "Arduino.h"
#include "SgEsp32Epaper_Screen.h"
#include "SgEsp32Epaper_Cfg.h"
#include "SgEsp32Epaper_Battery.h"
#include "SgEsp32Epaper_Eeprom.h"
#include "SgEsp32Epaper_DateTime.h"

#include "BatteryIcon.h"

#include "epd_driver.h"
#include "font_TitilliumWeb_16.h"
#include "font_TitilliumWeb_18.h"
#include "font_TitilliumWeb_20.h"
#include "font_TitilliumWeb_26.h"
#include "font_TitilliumWeb_SemiBold_26.h"
#include "font_TitilliumWeb_SemiBold_50.h"
#include "font_TitilliumWeb_SemiBold_52.h"
#include <WiFi.h>
#include <time.h>


#define SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTX   190
#define SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY   150

#define SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLEX 100
#define SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLEY 170
#define SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLER  70


SgEsp32Epaper_Screen::SgEsp32Epaper_Screen()
{  
  _framebuffer = (uint8_t *)ps_calloc(sizeof(uint8_t), EPD_WIDTH * EPD_HEIGHT / 2);
  if (!_framebuffer) {
      Serial.println("alloc memory failed !!!");
      while (1);
  }
  epd_init();
  memset(_framebuffer, 0xFF, EPD_WIDTH * EPD_HEIGHT / 2);
}


void SgEsp32Epaper_Screen::UpdateScreen(void)
{
  Serial.println("creating Sungrow object");
  SgEsp32Epaper_Sungrow Sungrow;

  _UpdateScreenInfobar();

  if( Sungrow.IsPvAvailable() )
  {
    // Now
    _UpdateScreenNow(Sungrow);

    //Today
    _UpdateScreenToday(Sungrow);
  } 

  //status
  _UpdateScreenStatus(Sungrow);

  epd_poweron();
  epd_clear();
  epd_draw_grayscale_image(epd_full_screen(), _framebuffer);
  epd_poweroff_all();
}

void SgEsp32Epaper_Screen::NightScreen(void)
{
  Serial.println("creating Sungrow object");
  SgEsp32Epaper_Sungrow Sungrow;

  _UpdateScreenInfobar();

  // Now
  _UpdateScreenNowSleep();

  //Today
  _UpdateScreenToday(Sungrow);

  //status
  _UpdateScreenStatusSleep();

  epd_poweron();
  epd_clear();
  epd_draw_grayscale_image(epd_full_screen(), _framebuffer);
  epd_poweroff_all();
}


/**
 * @brief Draw a partial ring to a given framebuffer.
 *
 * @param x0          Center-point x coordinate
 * @param y0          Center-point y coordinate
 * @param r_outer     Outer radius of the ring in pixels
 * @param r_inner     Inner radius of the ring in pixels
 * @param start_angle Start angle in degrees (0-360)
 * @param end_angle   End angle in degrees (0-360)
 * @param color       The gray value of the ring (0-255);
 */
void SgEsp32Epaper_Screen::_DrawPartialRing(int32_t x0, int32_t y0, int32_t r_outer, int32_t r_inner, float start_angle, float end_angle, uint8_t color) {
    float start_rad = start_angle * M_PI / 180.0f;
    float end_rad = end_angle * M_PI / 180.0f;

    for (float angle = start_rad; angle <= end_rad; angle += 0.01f) {
        for (int32_t r = r_inner; r <= r_outer; r++) {
            int32_t x = x0 + r * cos(angle);
            int32_t y = y0 + r * sin(angle);
            epd_draw_pixel(x, y, color, _framebuffer);
        }
    }
}


/**
 * @brief Draw a ring with two different gray levels and a gap to a given framebuffer.
 *
 * @param x0          Center-point x coordinate
 * @param y0          Center-point y coordinate
 * @param r_outer     Outer radius of the ring in pixels
 * @param r_inner     Inner radius of the ring in pixels
 * @param start_angle Starting angle for the first part of the ring in degrees (0-360)
 * @param pct1        Percentage of the ring to be colored with color1 (0-100)
 * @param pct2        Percentage of the ring to be colored with color2 (0-100)
 * @param gap_pct     Percentage of the ring to be left as a gap (0-100)
 * @param color1      The gray value of the first part of the ring (0-255);
 * @param color2      The gray value of the second part of the ring (0-255);
 * @param color3      The gray value of the third part of the ring (0-255);
 */
void SgEsp32Epaper_Screen::_DrawRing(int32_t x0, int32_t y0, int32_t r_outer, int32_t r_inner, float start_angle, uint8_t pct1, uint8_t pct2, uint8_t gap_pct, uint8_t color1, uint8_t color2, uint8_t color3) {
    float angle1 = 360.0f * pct1 / 100.0f;
    float angle2 = 360.0f * pct2 / 100.0f;
    float gap_angle = 360.0f * gap_pct / 100.0f;

    _DrawPartialRing(x0, y0, r_outer, r_inner, start_angle, start_angle + angle1, color1);
    _DrawPartialRing(x0, y0, r_outer, r_inner, start_angle + angle1, start_angle + angle1 + angle2, color2);
    _DrawPartialRing(x0, y0, r_outer, r_inner, start_angle + angle1 + angle2, start_angle + angle1 + angle2 + gap_angle, color3);
}


void SgEsp32Epaper_Screen::_UpdateScreenNow(SgEsp32Epaper_Sungrow& Sungrow)
{
  double PvGeneratingNow;
  double PvConsumingNow;
  int PercGeneratingNow;
  int PercConsumingNow;
  int PercRest;
  double PvGeneratedMax;

  /* *********************** Layout ************************ */
  int32_t CircleNowX = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLEX;
  int32_t CircleNowY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLEY;
  int32_t CircleNowR = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLER;

  int NowTextX = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTX;
  int NowTextY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY;

  int NowTextGeneratedX = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTX + 100;
  int NowTextGeneratedY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY;

  int NowTextGeneratedValueX = NowTextGeneratedX + 180;
  int NowTextGeneratedValueY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY;

  int NowTextConsumedX = NowTextGeneratedX;
  int NowTextConsumedY = NowTextGeneratedY + 50;

  int NowTextConsumedValueX = NowTextConsumedX + 180;
  int NowTextConsumedValueY = NowTextConsumedY;

  int NowTextAthGenX = NowTextGeneratedX;
  int NowTextAthGenY = NowTextConsumedY + 50;

  int NowTextAthGenValueX = NowTextConsumedX + 180;
  int NowTextAthGenValueY = NowTextAthGenY;
  /* *********************************************** */

  SgEsp32Epaper_Eeprom Eeprom;

  // load values from eeprom
  PvGeneratedMax = Eeprom.GetMaxPvPower();

  //load values from sungrow pv
  PvGeneratingNow = (double)Sungrow.ReadPowerFromPv();
  PvConsumingNow  = (double)Sungrow.ReadPowerFromPvToHome();

  if( PvGeneratingNow > PvGeneratedMax )
  {
    PvGeneratedMax = PvGeneratingNow;
    Eeprom.SetMaxPvPower(PvGeneratedMax);
  }

  if( PvGeneratingNow <= 0.0f )
  {
    _DrawPartialRing(CircleNowX, CircleNowY, CircleNowR, (CircleNowR - 30), 0, 360, 230);
  }
  else if( PvGeneratingNow < PvConsumingNow )
  {
    _DrawRing(CircleNowX, CircleNowY, CircleNowR, (CircleNowR - 30), 30, 0, 100, 0, 150, 200, 230);
  }
  else
  {
    PercGeneratingNow = ((PvGeneratingNow - PvConsumingNow) / PvGeneratedMax) * 100;
    PercConsumingNow  = (PvConsumingNow / PvGeneratedMax) * 100;
    PercRest          = ((PvGeneratedMax - PvGeneratingNow) / PvGeneratedMax) * 100;
    Serial.print("PercGeneratingNow: ");Serial.println(PercGeneratingNow);
    Serial.print("PercConsumingNow: ");Serial.println(PercConsumingNow);
    Serial.print("PercRest: ");Serial.println(PercRest);
    _DrawRing(CircleNowX, CircleNowY, CircleNowR, (CircleNowR - 30), 30, PercGeneratingNow, PercConsumingNow, PercRest, 150, 200, 230);
  }

  writeln((GFXfont *)&TitilliumWeb_16, "now", &NowTextX, &NowTextY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "generating", &NowTextGeneratedX, &NowTextGeneratedY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, String(PvGeneratingNow/1000).c_str(), &NowTextGeneratedValueX, &NowTextGeneratedValueY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, " kW", &NowTextGeneratedValueX, &NowTextGeneratedValueY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "consuming", &NowTextConsumedX, &NowTextConsumedY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, String(PvConsumingNow/1000).c_str(), &NowTextConsumedValueX, &NowTextConsumedValueY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, " kW", &NowTextConsumedValueX, &NowTextConsumedValueY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "a.t. max gen", &NowTextAthGenX, &NowTextAthGenY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, String(PvGeneratedMax/1000).c_str(), &NowTextAthGenValueX, &NowTextAthGenValueY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, " kW", &NowTextAthGenValueX, &NowTextAthGenValueY, _framebuffer);
}


void SgEsp32Epaper_Screen::_UpdateScreenNowSleep(void)
{
  double PvGeneratingNow;
  double PvConsumingNow;
  int PercGeneratingNow;
  int PercConsumingNow;
  int PercRest;
  double PvGeneratedMax;

  /* *********************** Layout ************************ */
  int32_t CircleNowX = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLEX;
  int32_t CircleNowY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLEY;
  int32_t CircleNowR = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLER;

  int NowTextX = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTX;
  int NowTextY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY;

  int NowTextGeneratedX = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTX + 100;
  int NowTextGeneratedY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY;

  int NowTextGeneratedValueX = NowTextGeneratedX + 180;
  int NowTextGeneratedValueY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY;

  int NowTextConsumedX = NowTextGeneratedX;
  int NowTextConsumedY = NowTextGeneratedY + 50;

  int NowTextConsumedValueX = NowTextConsumedX + 180;
  int NowTextConsumedValueY = NowTextConsumedY;

  int NowTextAthGenX = NowTextGeneratedX;
  int NowTextAthGenY = NowTextConsumedY + 50;

  int NowTextAthGenValueX = NowTextConsumedX + 180;
  int NowTextAthGenValueY = NowTextAthGenY;
  /* *********************************************** */

  SgEsp32Epaper_Eeprom Eeprom;

  // load values from eeprom
  PvGeneratedMax = Eeprom.GetMaxPvPower();


  _DrawPartialRing(CircleNowX, CircleNowY, CircleNowR, (CircleNowR - 30), 0, 360, 230);

  writeln((GFXfont *)&TitilliumWeb_16, "now", &NowTextX, &NowTextY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "generating", &NowTextGeneratedX, &NowTextGeneratedY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, "-", &NowTextGeneratedValueX, &NowTextGeneratedValueY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "consuming", &NowTextConsumedX, &NowTextConsumedY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, "-", &NowTextConsumedValueX, &NowTextConsumedValueY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "a.t. max gen", &NowTextAthGenX, &NowTextAthGenY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, String(PvGeneratedMax/1000).c_str(), &NowTextAthGenValueX, &NowTextAthGenValueY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, " kW", &NowTextAthGenValueX, &NowTextAthGenValueY, _framebuffer);
}


void SgEsp32Epaper_Screen::_UpdateScreenToday(SgEsp32Epaper_Sungrow& Sungrow)
{
  double ExportedEnergy;
  double UsedEnergy;
  double ImportedEnergy;
  int PercExportedEnergy;
  int PercUsedEnergy;
  
  ExportedEnergy = Sungrow.ReadDailyExportedEnergy();
  UsedEnergy = Sungrow.ReadDailyUsedEnergy();
  ImportedEnergy = Sungrow.ReadDailyImportedEnergy();

  PercExportedEnergy =  ( ExportedEnergy * 100)  / ( ExportedEnergy + UsedEnergy);
  PercUsedEnergy = 100 - PercExportedEnergy;


  /* *********************** Layout ************************ */
  int32_t CircleTodayX = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLEX;
  int32_t CircleTodayY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLEY + 180;
  int32_t CircleTodayR = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLER;

  int TodayTextX = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTX;
  int TodayTextY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY + 180;

  int TodayTextGeneratedX = TodayTextX + 100;
  int TodayTextGeneratedY = TodayTextY;

  int TodayTextGeneratedValueX = TodayTextGeneratedX + 180;
  int TodayTextGeneratedValueY = TodayTextY;

  int TodayTextConsumedX = TodayTextGeneratedX;
  int TodayTextConsumedY = TodayTextGeneratedY + 50;

  int TodayTextConsumedValueX = TodayTextConsumedX + 180;
  int TodayTextConsumedValueY = TodayTextConsumedY;

  int TodayTextImportedX = TodayTextGeneratedX;
  int TodayTextImportedY = TodayTextConsumedY + 50;

  int TodayTextImportedValueX = TodayTextImportedX + 180;
  int TodayTextImportedValueY = TodayTextImportedY;

  /* *********************************************** */

  _DrawRing(CircleTodayX, CircleTodayY, CircleTodayR, (CircleTodayR - 30), 30, PercExportedEnergy, PercUsedEnergy, 0.0f, 150, 200, 255);

  writeln((GFXfont *)&TitilliumWeb_16, "today", &TodayTextX, &TodayTextY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "generated", &TodayTextGeneratedX, &TodayTextGeneratedY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, String(ExportedEnergy+UsedEnergy).c_str(), &TodayTextGeneratedValueX, &TodayTextGeneratedValueY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, " kW/h", &TodayTextGeneratedValueX, &TodayTextGeneratedValueY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "consumed", &TodayTextConsumedX, &TodayTextConsumedY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, String(UsedEnergy).c_str(), &TodayTextConsumedValueX, &TodayTextConsumedValueY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, " kW/h", &TodayTextConsumedValueX, &TodayTextConsumedValueY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "imported", &TodayTextImportedX, &TodayTextImportedY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, String(ImportedEnergy).c_str(), &TodayTextImportedValueX, &TodayTextImportedValueY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, " kW/h", &TodayTextImportedValueX, &TodayTextImportedValueY, _framebuffer);
}


void SgEsp32Epaper_Screen::_UpdateScreenStatus(SgEsp32Epaper_Sungrow& Sungrow)
{
  /* *********************** Layout ************************ */
  int VLineX = 650;
  int VLineY = 80;

  int StatusTextX = VLineX + 20;
  int StatusTextY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY;

  int StatusValueX = StatusTextX + 120;
  int StatusValueY = StatusTextY;

  int String2TextX = StatusTextX;
  int String2TextY = StatusTextY + 70;

  int String2ValueX = StatusTextX + 120;
  int String2ValueY = String2TextY;

  int String1TextX = StatusTextX;
  int String1TextY = String2TextY + 50;

  int String1ValueX = StatusTextX + 120;
  int String1ValueY = String1TextY;

//DEBUG

  int DebugX = StatusTextX;
  int DebugY = String1TextY + 70;

  int DebugValueX = StatusTextX + 120;
  int DebugValueY = DebugY;



  /* *********************************************** */

  if( Sungrow.IsPvAvailable() )
  {
  // vertical line
    epd_draw_vline(VLineX, VLineY, EPD_HEIGHT - 160, 50, _framebuffer);


    // status
    writeln((GFXfont *)&TitilliumWeb_16, "status", &StatusTextX, &StatusTextY, _framebuffer);
    if( Sungrow.IsPvGenerating() )
    {
      writeln((GFXfont *)&TitilliumWeb_16, "generating", &StatusValueX, &StatusValueY, _framebuffer);
    }
    else
    {
      writeln((GFXfont *)&TitilliumWeb_16, "idle", &StatusValueX, &StatusValueY, _framebuffer);
    }

    writeln((GFXfont *)&TitilliumWeb_16, "east", &String2TextX, &String2TextY, _framebuffer);
    writeln((GFXfont *)&TitilliumWeb_16, String(Sungrow.ReadPowerString2()/1000).c_str(), &String2ValueX, &String2ValueY, _framebuffer);
    writeln((GFXfont *)&TitilliumWeb_16, " kW", &String2ValueX, &String2ValueY, _framebuffer);

    writeln((GFXfont *)&TitilliumWeb_16, "west", &String1TextX, &String1TextY, _framebuffer);
    writeln((GFXfont *)&TitilliumWeb_16, String(Sungrow.ReadPowerString1()/1000).c_str(), &String1ValueX, &String1ValueY, _framebuffer);
    writeln((GFXfont *)&TitilliumWeb_16, " kW", &String1ValueX, &String1ValueY, _framebuffer);
  }
  else
  {
    // vertical line
    epd_draw_vline(VLineX, VLineY, EPD_HEIGHT - 160, 50, _framebuffer);

    // status
    writeln((GFXfont *)&TitilliumWeb_16, "status", &StatusTextX, &StatusTextY, _framebuffer);
    writeln((GFXfont *)&TitilliumWeb_16, "disconnected", &StatusValueX, &StatusValueY, _framebuffer);
  }

  //DEBUG
  // status
    SgEsp32Epaper_Battery Battery;
    writeln((GFXfont *)&TitilliumWeb_16, "Dbg.Bat.", &DebugX, &DebugY, _framebuffer);
    writeln((GFXfont *)&TitilliumWeb_16, String(Battery.GetBatteryVoltage()).c_str(), &DebugValueX, &DebugValueY, _framebuffer);
    writeln((GFXfont *)&TitilliumWeb_16, "V", &DebugValueX, &DebugValueY, _framebuffer);

}


void SgEsp32Epaper_Screen::_UpdateScreenStatusSleep(void)
{
  /* *********************** Layout ************************ */
  int VLineX = 650;
  int VLineY = 80;

  int StatusTextX = VLineX + 20;
  int StatusTextY = SGESP32EPAPER_SCREEN_LAYOUT_NOW_TEXTY;

  int StatusValueX = StatusTextX + 120;
  int StatusValueY = StatusTextY;

  int String2TextX = StatusTextX;
  int String2TextY = StatusTextY + 70;

  int String2ValueX = StatusTextX + 120;
  int String2ValueY = String2TextY;

  int String1TextX = StatusTextX;
  int String1TextY = String2TextY + 50;

  int String1ValueX = StatusTextX + 120;
  int String1ValueY = String1TextY;
  /* *********************************************** */


  // vertical line
  epd_draw_vline(VLineX, VLineY, EPD_HEIGHT - 160, 50, _framebuffer);

  // status
  writeln((GFXfont *)&TitilliumWeb_16, "status", &StatusTextX, &StatusTextY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, "sleeping", &StatusValueX, &StatusValueY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "east", &String2TextX, &String2TextY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, "-", &String2ValueX, &String2ValueY, _framebuffer);

  writeln((GFXfont *)&TitilliumWeb_16, "west", &String1TextX, &String1TextY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, "-", &String1ValueX, &String1ValueY, _framebuffer);

}  


void SgEsp32Epaper_Screen::_UpdateScreenInfobar(void)
{
  int BatteryStatus;
  time_t NowTimestamp;
  SgEsp32Epaper_Battery Battery;
  SgEsp32Epaper_DateTime DateTime;

  // get battery/usb information
  BatteryStatus = Battery.GetBatteryStatus();

  NowTimestamp = DateTime.GetDateTime();

  /* *********************** Layout ************************ */
  //battery image
  Rect_t area_battery = {
        .x = 879,
        .y = 10,
        .width = Battery_width,
        .height = Battery_height
  };

  int InfoTimeX = 15;
  int infoTimeY = 50;

  int InfoTextX = SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLEX - SGESP32EPAPER_SCREEN_LAYOUT_NOW_CIRCLER;
  int InfoTextY = 500;

  int InfoTextHomeX = InfoTextX + 350;

  int InfoBlockHomeX = InfoTextHomeX - 30;
  int InfoBlockHomeY = InfoTextY - 20;

  int InfoTextGridX = InfoTextX + 670;

  int InfoBlockGridX = InfoTextGridX - 30;
  int InfoBlockGridY = InfoTextY - 20;

  //top
  writeln((GFXfont *)&TitilliumWeb_16, "last update: ", &InfoTimeX, &infoTimeY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, String(ctime(&NowTimestamp)).c_str(), &InfoTimeX, &infoTimeY, _framebuffer);

  epd_draw_hline( 10, 54, EPD_WIDTH-20, 0, _framebuffer );
  epd_draw_hline( 10, 55, EPD_WIDTH-20, 0, _framebuffer );
  epd_draw_hline( 10, 56, EPD_WIDTH-20, 0, _framebuffer );

  switch(BatteryStatus)
  {
    case SG32EPAPER_BATTERY_STATUS_USB:
      epd_copy_to_framebuffer(area_battery, (uint8_t *) BatteryUsb_data, _framebuffer);
      break;

    case SG32EPAPER_BATTERY_STATUS_99P:
      epd_copy_to_framebuffer(area_battery, (uint8_t *) BatteryP99_data, _framebuffer);
      break;

    case SG32EPAPER_BATTERY_STATUS_66P:
      epd_copy_to_framebuffer(area_battery, (uint8_t *) BatteryP66_data, _framebuffer);
      break;

    case SG32EPAPER_BATTERY_STATUS_33P:
      epd_copy_to_framebuffer(area_battery, (uint8_t *) BatteryP33_data, _framebuffer);
      break;

    default:
      epd_copy_to_framebuffer(area_battery, (uint8_t *) BatteryP0_data, _framebuffer);
      //ALARM
      //analogWrite(BUZZERPIN, 20);
      //AddSystemMessage("ALARM! Battery voltage low.");
      break;
  }

  //bottom
  writeln((GFXfont *)&TitilliumWeb_16, "PV generated power", &InfoTextX, &InfoTextY, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, "consumed at home", &InfoTextHomeX, &InfoTextY, _framebuffer);
  epd_fill_rect(InfoBlockHomeX, InfoBlockHomeY, 20, 20, 200, _framebuffer);
  writeln((GFXfont *)&TitilliumWeb_16, "exported to grid", &InfoTextGridX, &InfoTextY, _framebuffer);
  epd_fill_rect(InfoBlockGridX, InfoBlockGridY, 20, 20, 150, _framebuffer);
}