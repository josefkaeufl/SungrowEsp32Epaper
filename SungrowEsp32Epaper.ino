#include "Arduino.h"

#include "SgEsp32Epaper_Screen.h"
#include "SgEsp32Epaper_DateTime.h"
#include "SgEsp32Epaper_Wifi.h"



void setup() {

  Serial.begin(115200);

  Serial.println("creating Wifi object");
  SgEsp32Epaper_Wifi WifiObj;
  (void)WifiObj.Connect();

}

void loop() {

  SgEsp32Epaper_DateTime DateTimeObj;
  SgEsp32Epaper_Screen ScreenObj;

  if( DateTimeObj.IsTimeToSleep(21) )
  {
    uint64_t NightSleepTime;
    // calculate time until night is over
    NightSleepTime = DateTimeObj.GetTimeUntilWakeup(6); // [s]
    Serial.print("calculated time [s] until wakeup: ");
    Serial.println(NightSleepTime);

    ScreenObj.NightScreen();

    esp_sleep_enable_timer_wakeup(NightSleepTime * 1000 * 1000);
  }
  else
  {
    Serial.println("creating Screen object");
    
    ScreenObj.UpdateScreen();
    
    Serial.println("Going to sleep now");
    delay(100);
    Serial.flush(); 

    esp_sleep_enable_timer_wakeup(1000000 * 60 * 2); // (24 * 6 / 2) = 72 Aufrufe

    esp_deep_sleep_start();
  }

  Serial.println("This will never be printed");
  while(1){;}
}
