//
// cmake-Template für config.h
//

#ifndef SONOFFALEXA_CONFIG_H_IN_H
#define SONOFFALEXA_CONFIG_H_IN_H

#include <Arduino.h>

// the configured options and settings for HelloWorld
const String SonoffAlexa_VERSION_MAJOR = "0";
const String SonoffAlexa_VERSION_MINOR = "1";

// Password compiled into source
// Set in .config/passwords.cmake (or via ENV-VAR)
const String SonoffAlexa_PASSWORD_LS = "add your password 4 NW II";
const String SonoffAlexa_PASSWORD_TPL = "add your password 4 NW II";

#endif //SONOFFALEXA_CONFIG_H_IN_H
