# PlatformIO / Sonoff / Alexa

Small sample that shows how to setup and program a basic Sonoff-Device

<p align="center">
    <img src="https://raw.githubusercontent.com/MikeMitterer/cpp-sonoff/master/doc/images/sonoff.jpg" alt="Sonoff" />
</p>

You can go into programming-mode by:

   - Turn off VCC
   - Hold Sonoff-Button
   - Turn back on VCC
   - Release Sonoff-Button
   
## What I figured out
   
In my case uploading the firmware to the device worked fine but the LED did not start blinking.

I had to switch the `board_flash_mode` to **dout**! (`platformio.ini`)    

## Usage

   - Change password in `.config/passwords.cmake`
   - Change SSID in `main.cpp`
   - Change keyword for Alexa in `main.cpp`
   
#### PUT

    # Turn relay on 
    # (My DNS-Server maps the Sonoff MAC to sonoff1)
    curl -X PUT http://sonoff1/relay/1/on 

### REST Commands

    /**
     * +-------------+-----------------------------------------+-------------------------+
     * | HTTP Method |                  URI                    |         Action          |
     * +-------------+-----------------------------------------+-------------------------+
     * | GET         | http://[hostname]/api/v1/jobs           | Retrieve list of jobs   |
     * | GET         | http://[hostname]/api/v1/jobs/[task_id] | Retrieve a job          |
     * | POST        | http://[hostname]/api/v1/jobs           | Create a new job        |
     * | PUT         | http://[hostname]/api/v1/jobs/[task_id] | Update an existing job  |
     * | DELETE      | http://[hostname]/api/v1/jobs/[task_id] | Delete a job            |
     * +-------------+-----------------------------------------+-------------------------+
     * http://www.sensefulsolutions.com/2010/10/format-text-as-table.html
     */
   
### License 

    Copyright 2017 Michael Mitterer (office@mikemitterer.at),
    IT-Consulting and Development Limited, Austrian Branch

         _    _                
        / \  | | _____  ____ _ 
       / _ \ | |/ _ \ \/ / _` |
      / ___ \| |  __/>  < (_| |
     /_/   \_\_|\___/_/\_\__,_|

                                                            
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing,
    software distributed under the License is distributed on an
    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
    either express or implied. See the License for the specific language
    governing permissions and limitations under the License.


If this plugin is helpful for you - please [(Circle)](http://gplus.mikemitterer.at/) me
or **star** this repo here on GitHub