#ifndef SG32EPAPER_DATETIME
#define SG32EPAPER_DATETIME

#include "Arduino.h"
#include <time.h>

class SgEsp32Epaper_DateTime
{
  public:
    SgEsp32Epaper_DateTime();
    time_t GetDateTime(void);
    bool IsTimeToSleep(int SleepHour);
    time_t GetTimeUntilWakeup(int WakeupHour);
    
  private:
    
};

#endif