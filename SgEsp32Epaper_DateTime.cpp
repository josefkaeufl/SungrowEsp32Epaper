#include "Arduino.h"
#include "SgEsp32Epaper_DateTime.h"
#include <WiFi.h>

SgEsp32Epaper_DateTime::SgEsp32Epaper_DateTime()
{
  ;
}


time_t SgEsp32Epaper_DateTime::GetDateTime(void)
{
  time_t now;
  tm tm;

  // Überprüfen der Netzwerkverbindung
  if (WiFi.status() != WL_CONNECTED)
  {
    // Keine Verbindung zum WLAN
    Serial.println("Keine Netzwerkverbindung");
    now = 0;
  }
  
  //init and get the time
  Serial.print("Initializing time from compiler tools ");
  configTime(0, 0, "pool.ntp.org");
  setenv("TZ", "CET-1CEST,M3.5.0/2,M10.5.0/3", 1);  // Zeitzone und Sommerzeitregelung für Deutschland

  while (true)
  {
    Serial.print(".");
    time(&now);
    localtime_r(&now, &tm);
    if (tm.tm_year >= 122)
      break;
    delay(500);
  }
  Serial.println("ok");

  return now;
}

bool SgEsp32Epaper_DateTime::IsTimeToSleep(int SleepHour)
{
  time_t Now;
  tm Tm;
  bool RetVal;

  RetVal = false;

  Now = GetDateTime();
  localtime_r(&Now, &Tm);

  if (Tm.tm_hour >= SleepHour)
  {
    RetVal = true;
  }
  
  return RetVal;
}

time_t SgEsp32Epaper_DateTime::GetTimeUntilWakeup(int WakeupHour)
{
  time_t Now;
  time_t WakeupTime;
  time_t NewTime;
  tm Tm;

  Now = GetDateTime();
  localtime_r(&Now, &Tm);

  if( Tm.tm_hour <= WakeupHour )
  {
    // already same day
  }
  else
  {
    // day before
    NewTime = Now;
    NewTime += 24 * 60 * 60; // inkrement by one day
    localtime_r(&NewTime, &Tm);
  }
  
  // set hour
  Tm.tm_hour = WakeupHour;
  Tm.tm_min = 0;
  Tm.tm_sec = 0;

  WakeupTime = mktime(&Tm);

  Serial.print("WakeupTime: ");Serial.println(WakeupTime);
  Serial.print("Now: ");Serial.println(Now);

  return (WakeupTime-Now);
}


