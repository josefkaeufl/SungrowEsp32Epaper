#ifndef SGESP32EPAPER_SCREEN
#define SGESP32EPAPER_SCREEN

#include "Arduino.h"


#include "SgEsp32Epaper_Sungrow.h"


class SgEsp32Epaper_Screen
{
  public:
    SgEsp32Epaper_Screen();
    void UpdateScreen(void);
    void NightScreen(void);
    
  private:
    uint8_t* _framebuffer;
    void _DrawPartialRing(int32_t x0, int32_t y0, int32_t r_outer, int32_t r_inner, float start_angle, float end_angle, uint8_t color);
    void _DrawRing(int32_t x0, int32_t y0, int32_t r_outer, int32_t r_inner, float start_angle, uint8_t pct1, uint8_t pct2, uint8_t gap_pct, uint8_t color1, uint8_t color2, uint8_t color3);
    void _UpdateScreenNow(SgEsp32Epaper_Sungrow& Sungrow);
    void _UpdateScreenToday(SgEsp32Epaper_Sungrow& Sungrow);
    void _UpdateScreenStatus(SgEsp32Epaper_Sungrow& Sungrow);
    void _UpdateScreenInfobar(void);
    void _UpdateScreenNowSleep(void);
    void _UpdateScreenStatusSleep(void);
};

#endif
