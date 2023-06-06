#ifndef SGESP32EPAPER_EEPROM
#define SGESP32EPAPER_EEPROM

#include "Arduino.h"
#include <Preferences.h>

class SgEsp32Epaper_Eeprom
{
  public:

    void SetWlanSsid(const char* pc_Ssid);
    char* GetWlanSsid(void); 

    void SetWlanPswd(const char* pc_Pswd);
    char* GetWlanPswd(void); 

    void SetMaxPvPower(double d_PvPower);
    double GetMaxPvPower(void);
    
  private:
    Preferences _preferences;
};

#endif
