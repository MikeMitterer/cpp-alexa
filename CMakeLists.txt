cmake_minimum_required(VERSION 3.2)
project(SonoffAlexa)

include(CMakeListsPrivate.txt)

# Password for this project
include(.config/passwords.cmake)

# The version number.
set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
        "${PROJECT_SOURCE_DIR}/.config/config.h.in"
        "${PROJECT_SOURCE_DIR}/src/config.h"
        @ONLY
)

add_custom_target(
    PLATFORMIO_UPLOAD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_CLEAN ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target clean
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPDATE_ALL ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion update
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


include_directories(include)
include_directories(src)

file(GLOB_RECURSE HEADER_FILES src/*.h)

# - libs
set(_ESP8266_HINT "lib/private_lib")
include_directories(${_ESP8266_HINT})

#set(_ESP8266_SRC
#        "${_ESP8266_HINT}/esp8266/esp8266.cpp"
#        "${_ESP8266_HINT}/esp8266/esp8266.h"
#        )

set(SOURCE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/${_ESP8266_HINT}/esp8266.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/${_ESP8266_HINT}/esp8266.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/${_ESP8266_HINT}/eventHandler.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/${_ESP8266_HINT}/eventHandler.cpp"
        
        src/main.cpp
        )

message(${SOURCE_FILES})

add_executable(${PROJECT_NAME}
        ${HEADER_FILES} ${SOURCE_FILES}
        )
