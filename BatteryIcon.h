#pragma once

const uint32_t Battery_width  = 70;  //  = 2 x dot2pic.com :: 35
const uint32_t Battery_height = 35;  //  =     dot2pic.com :: 35

//Created using dot2pic.com

// 99%
const uint8_t BatteryP99_data[] = 
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

// 66%
const uint8_t BatteryP66_data[] = 
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

// 33%
const uint8_t BatteryP33_data[] = 
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

// 0%
const uint8_t BatteryP0_data[] = 
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

// USB
const uint8_t BatteryUsb_data[] =
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};