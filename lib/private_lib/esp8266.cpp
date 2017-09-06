//
// Created by Mike Mitterer on 28.08.17.
//

#include "esp8266.h"
#include <fauxmoESP.h>

void showMacAddress() {
    uint8_t address[6];

    WiFi.macAddress(address);

    Serial.print("MAC: ");
    for (int index = 0; index < sizeof(address); index++) {
        Serial.print(address[index], HEX);

        if (index < sizeof(address) - 1) {
            Serial.print(":");
        }
    }
    Serial.println("");
}

void setupWIFI(const String& ssid, const String& pw, const uint8_t wifiIndicatorLED) {
    // Status-LED off
    digitalWrite(wifiIndicatorLED, LOW);

    // Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
    // would try to act as both a client and an access-point and could cause
    // network-issues with your other WiFi-devices on your WiFi-network.
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), pw.c_str());

    while (WiFi.status() != WL_CONNECTED) {
        delay(300);
        digitalWrite(wifiIndicatorLED, HIGH);

        delay(200);
        digitalWrite(wifiIndicatorLED, LOW);

        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected!");

    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    showMacAddress();

    // Status auf ON!
    digitalWrite(wifiIndicatorLED, HIGH);
}


