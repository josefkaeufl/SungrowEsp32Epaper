#include "Arduino.h"
#include "SgEsp32Epaper_Battery.h"
#include "esp_adc_cal.h"
#include "epd_driver.h"

#define BATT_PIN            36


SgEsp32Epaper_Battery::SgEsp32Epaper_Battery()
{
  // Correct the ADC reference voltage
  esp_adc_cal_characteristics_t adc_chars;
  esp_adc_cal_value_t val_type = esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);

  Serial.println("Init battery: ");
  
  if (val_type == ESP_ADC_CAL_VAL_EFUSE_VREF)
  {
    String debug = "eFuse Vref:" + String(adc_chars.vref) + " mV";
    Serial.println(debug);
        
    _Vref = adc_chars.vref;
  }
}

int SgEsp32Epaper_Battery::GetBatteryStatus(void)
{
  int retVal;
  
  // When reading the battery voltage, POWER_EN must be turned on
  epd_poweron();
  delay(10); // Make adc measurement more accurate
  
  uint16_t v = analogRead(BATT_PIN);
  
  float battery_voltage = ((float)v / 4095.0) * 2.0 * 3.3 * (_Vref / 1000.0);
  String voltage = "Voltage: " + String(battery_voltage) + "V";
  
  Serial.println(voltage);

  epd_poweroff_all();

  if(battery_voltage >= (float)4.7)
  {
    retVal = SG32EPAPER_BATTERY_STATUS_USB;
  }
  else if(battery_voltage >= (float)3.80)
  {
    retVal = SG32EPAPER_BATTERY_STATUS_99P;
  }
  else if(battery_voltage >= (float)3.60)
  {
    retVal = SG32EPAPER_BATTERY_STATUS_66P;
  }
  else if(battery_voltage >= (float)3.45)
  {
    retVal = SG32EPAPER_BATTERY_STATUS_33P;
  }
  else
  {
    retVal = SG32EPAPER_BATTERY_STATUS_0P;
  }

  return retVal;
}


float SgEsp32Epaper_Battery::GetBatteryVoltage(void)
{
  // When reading the battery voltage, POWER_EN must be turned on
  epd_poweron();
  delay(10); // Make adc measurement more accurate
  
  uint16_t v = analogRead(BATT_PIN);
  
  float battery_voltage = ((float)v / 4095.0) * 2.0 * 3.3 * (_Vref / 1000.0);

  epd_poweroff_all();

  return battery_voltage;
}
