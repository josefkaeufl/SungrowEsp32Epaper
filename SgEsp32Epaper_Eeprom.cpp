#include "Arduino.h"
#include "SgEsp32Epaper_Eeprom.h"
#include "SgEsp32Epaper_Cfg.h"


#define LOCATION_WLANSSID    "WLAN_SSID"
#define LOCATION_WLANPSWD    "WLAN_PASSWORD"
#define LOCATION_PVPOWER     "PV_POWER"


void SgEsp32Epaper_Eeprom::SetWlanSsid(const char* pc_Ssid)
{
  _preferences.begin("SgEsp32Epaper", false); 
  _preferences.putString(LOCATION_WLANSSID, pc_Ssid);
  _preferences.end();
}

char* SgEsp32Epaper_Eeprom::GetWlanSsid(void)
{
  static char retval[256];
  
  _preferences.begin("SgEsp32Epaper", false); 

  strcpy(retval, _preferences.getString(LOCATION_WLANSSID, "").c_str());
  if( retval[0] == '\0' )
  {
    Serial.println("Wlan SSID was empty. Using default SSID instead!");
    strcpy(retval, DEFAULT_WLAN_SSID);
  }
  _preferences.end();
  
  return retval;
}




void SgEsp32Epaper_Eeprom::SetWlanPswd(const char* pc_Pswd)
{ 
  _preferences.begin("SgEsp32Epaper", false); 
  _preferences.putString(LOCATION_WLANPSWD, pc_Pswd);
  _preferences.end();
}

char* SgEsp32Epaper_Eeprom::GetWlanPswd(void)
{
  static char retval[256];

  retval[0] = 0xFF;
  
  _preferences.begin("SgEsp32Epaper", false); 

  strcpy(retval, _preferences.getString(LOCATION_WLANPSWD, "").c_str());
  if( retval[0] == '\0' )
  {
    Serial.println("Wlan password was empty. Using default password instead!");
    strcpy(retval, DEFAULT_WLAN_PASSWORD);
  }
  _preferences.end();
  
  return retval;
}


void SgEsp32Epaper_Eeprom::SetMaxPvPower(double d_PvPower)
{
  _preferences.begin("SgEsp32Epaper", false); 
  _preferences.putDouble(LOCATION_PVPOWER, d_PvPower);
  _preferences.end();
}

double SgEsp32Epaper_Eeprom::GetMaxPvPower(void)
{
  double retval;
  
  _preferences.begin("SgEsp32Epaper", false); 

  retval = _preferences.getDouble(LOCATION_PVPOWER, 0.0f);
  if( retval == 0.0f )
  {
    Serial.println("EEPROM was empty. Using default value 0.");
  }
  _preferences.end();
  
  return retval;
}

