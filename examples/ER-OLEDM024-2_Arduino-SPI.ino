/***************************************************
//Web: http://www.buydisplay.com
EastRising Technology Co.,LTD
Examples for ER-OLEDM024-2
Display is Hardward SPI 4-Wire SPI Interface 
Tested and worked with:
Works with Arduino 1.6.0 IDE  
Test OK : Arduino DUE,Arduino mega2560,Arduino UNO Board 
****************************************************/

/*
Note:The module needs to be jumpered to an SPI interface. R19,R21 Short and R18,R20 Open  
  Unused signal pin Recommended to connect to GND 
  == Hardware connection ==
    OLED   =>    Arduino
  *1. GND    ->    GND
  *2. VCC    ->    3.3
  *4. DC     ->    9    
  *7. SCL    ->    SCK
  *8. SDA    ->    MOSI  
  *15. CS    ->    10 
  *16. RES    ->    8
*/

#include <SPI.h>
#include "er_oled.h"

uint8_t oled_buf[WIDTH * HEIGHT / 8];

void setup() {
  Serial.begin(9600);
  
  er_oled_clear(oled_buf);
  /* display images of bitmap matrix */
  er_oled_bitmap(0, 2, Signal816, 16, 8, oled_buf); 
  er_oled_bitmap(24, 2,Bluetooth88, 8, 8, oled_buf); 
  er_oled_bitmap(40, 2, Msg816, 16, 8, oled_buf); 
  er_oled_bitmap(64, 2, GPRS88, 8, 8, oled_buf); 
  er_oled_bitmap(90, 2, Alarm88, 8, 8, oled_buf); 
  er_oled_bitmap(112, 2, Bat816, 16, 8, oled_buf); 

  er_oled_string(10, 52, "www.buydisplay.com", 12, 1, oled_buf); 
 

  er_oled_char3216(0, 16, '1', oled_buf);
  er_oled_char3216(16, 16, '2', oled_buf);
  er_oled_char3216(32, 16, ':', oled_buf);
  er_oled_char3216(48, 16, '3', oled_buf);
  er_oled_char3216(64, 16, '4', oled_buf);
  er_oled_char3216(80, 16, ':', oled_buf);
  er_oled_char3216(96, 16, '5', oled_buf);
  er_oled_char3216(112, 16, '6', oled_buf);

  er_oled_display(oled_buf); 
}

void loop() {

}

