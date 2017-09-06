//
// Created by Mike Mitterer on 28.08.17.
//

#ifndef MM_ESP8266_H
#define MM_ESP8266_H

#include <Arduino.h>

void showMacAddress();
void setupWIFI(const String& ssid, const String& pw,const uint8_t wifiIndicatorLED);

#endif // MM_ESP8266_H