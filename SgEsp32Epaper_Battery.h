#ifndef SG32EPAPER_BATTERY
#define SG32EPAPER_BATTERY

#include "Arduino.h"

#define SG32EPAPER_BATTERY_STATUS_99P     4
#define SG32EPAPER_BATTERY_STATUS_66P     3
#define SG32EPAPER_BATTERY_STATUS_33P     2
#define SG32EPAPER_BATTERY_STATUS_0P      1
#define SG32EPAPER_BATTERY_STATUS_USB     0

class SgEsp32Epaper_Battery
{
  public:
    SgEsp32Epaper_Battery();
    int GetBatteryStatus(void);
    float GetBatteryVoltage(void);
    
  private:
    int _Vref;
    
};

#endif
