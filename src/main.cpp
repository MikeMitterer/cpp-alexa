#include "pins.h"
#include "esp8266.h"
#include "config.h"
#include "eventHandler.h"

const uint8_t PORT = 80;

enum class States {
    Idle,
    LedOn, LedOff,
    RelayOn, RelayOff,
};

const uint8_t wifiIndicatorLED = IOPIN_LED;

// Internal network I (192.168.0.0/24)
const String ssid = "MikeMitterer-LS";
const String password = SonoffAlexa_PASSWORD_LS;

// Internal network II (192.168.1.0/24)
// const String ssid = "MikeMitterer-TPL";
// const String password = ControlNani_PASSWORD_TPL;

// Control Relays via GET-Request
AsyncWebServer server(PORT);

// Control via Alexa
fauxmoESP fauxmo;

// Main-Status
States state = States::Idle;


// the setup function runs once when you press reset or power the board
void setup() {

    // Setup Pins
    pinMode(IOPIN_LED, OUTPUT);

    // Setup Serial
    Serial.begin(115200);
    Serial.println("Booting...");
    delay(10);

    // Setup WIFI
    setupWIFI(ssid, password, wifiIndicatorLED);
    showMacAddress();

    // Setup Server
    server.onNotFound(handleNotFound);

    server.on("/relay/1/on", HTTP_PUT, [&](AsyncWebServerRequest *request) {
        state = States::RelayOn; request->send(204); });

    server.on("/relay/1/off", HTTP_PUT, [&](AsyncWebServerRequest *request) {
        state = States::RelayOff; request->send(204); });

    fauxmo.addDevice("stehlampe");
    fauxmo.onMessage([](unsigned char device_id, const char* device_name, bool alexaState) {
        
        Serial.printf("[MAIN] Device #%d (%s) state: %s\n",
                      device_id, device_name, alexaState ? "ON" : "OFF");

        String deviceName = String(device_name);
        if(deviceName == "stehlampe") {
            state = alexaState ? States::RelayOn : States::RelayOff;
        }
    });
    
    server.begin();

    // Done!
    Serial.println("Done!");
}

// the loop function runs over and over again forever
void loop() {

    switch(state) {
        case States::LedOn:
        case States::RelayOn:
            digitalWrite(wifiIndicatorLED, LOW);
            digitalWrite(IOPIN_RELAY, LOW);
            state = States::Idle;
            break;

        case States::LedOff:
        case States::RelayOff:
            digitalWrite(wifiIndicatorLED, HIGH);
            digitalWrite(IOPIN_RELAY, HIGH);
            state = States::Idle;
            break;

        default:
            yield();
    }

    fauxmo.handle();
    yield();
}

