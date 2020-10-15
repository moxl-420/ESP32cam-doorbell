# ESP32cam-doorbell



**ESP32-CAM Doorbell**
*Low budget version*

**Needed**
- ESP32-CAM AI-Thinker
- 5v 1amp power supply (eg: phone charger)
- 5v Led momentary button (which includes a resistor)
- Universal phone fisheye lens.
- 2 x 1k resistor
- 16v 100mf capacitor
- A way to flash the ESP32-CAM (FTDI adapters are cheap)
- A post image server (LAMP)

**Install LAMP server**
Can be done on multiple ways, I run a RaspberryPi Virtual Machine on a windows server.
See tutorial: 
*https://randomnerdtutorials.com/esp32-cam-post-image-photo-server/*

 *A manual install of phpmyadmin might be needed.*
 *"http://192.168.x.x/gallery.php" is the location you will find your pictures.*

**see github projectfiles:**
*https://github.com/moxl-420/ESP32cam-doorbell*

**see wiring and download gerberfile:**
*https://easyeda.com/moxl/doorbell*

**see Thingiverseto download stl.**
*https://www.thingiverse.com/thing:4602738*

**Use Github files**
**!!! This needs to be build in platform.io. !!!**

 BaudRate: 115200
- Adapt config.h  to change the user parameters and connection to wifi.

**Default pins  (change in config.h)**

- Button = 12     (1K resistor pulled to ground)
- Led =  13       (you need a resistor if your led in the button doesn't come with one) 
- Buzzer = 15     (2n222 NPN with 1k resistor.)

Wiring can be found:
*https://easyeda.com/moxl/doorbell*

*Thanks to Reddit/r/esp32*
