#include "Arduino.h"
#include "SgEsp32Epaper_Wifi.h"
#include "SgEsp32Epaper_Eeprom.h"
#include "SgEsp32Epaper_Cfg.h"
#include <WiFi.h>


SgEsp32Epaper_Wifi::SgEsp32Epaper_Wifi()
{
  ;
}

bool SgEsp32Epaper_Wifi::Connect(void)
{
  int WifiConnectStartTime;
  bool areDefaultCredentialsUsed = false;
  bool retValue = true;

  char* WlanSsid;
  char* WlanPswd;
  
  // load values from eeprom
  SgEsp32Epaper_Eeprom Eeprom;
  WlanSsid = Eeprom.GetWlanSsid();
  WlanPswd = Eeprom.GetWlanPswd();

  WifiConnectStartTime = millis();

  if( strcmp(WlanPswd, "NULL") == 0 )
  {
    WiFi.begin(WlanSsid);
  }
  else
  {
    WiFi.begin(WlanSsid, WlanPswd);
  }

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");

    if( millis() - WifiConnectStartTime > 10000 )
    {
      if( areDefaultCredentialsUsed == false )
      {
        // abort time 10sec
        Serial.println("Timeout. Use default values instead.");
        Serial.print("Connecting to WiFi");
        
        WiFi.begin(DEFAULT_WLAN_SSID, DEFAULT_WLAN_PASSWORD);
        
        WifiConnectStartTime = millis();
        areDefaultCredentialsUsed = true;
      }
      else
      {
        retValue = false;
      }
    }
  }

  Serial.println("done");
  return retValue;
}
