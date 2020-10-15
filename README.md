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

**see github projectfiles: **
*https://github.com/moxl-420/ESP32cam-doorbell*

**see wiring and download gerberfile:**
*https://easyeda.com/moxl/doorbell*

**see Thingiverseto download stl.**
*https://www.thingiverse.com/thing:4602738*







This is not a functional repo at the moment.

ESP32cam-doorbell

 Written by moxl
 
 BaudRate: 115200
 
Adapt chime.h   to change the sound produced by the speaker (Not required)
Adapt config.h  to change the user parameters

By Default pins  (change in config.h)


Button = 12     (1K resistor pulled to ground)

Led =  13       (you need a resistor if your led in the button doesn't come with one) 

Buzzer = 15     (2n222 NPN with 1k resistor.)

Wiring can be found https://www.thingiverse.com/thing:4602738

For the LAMP server part on raspberry (or RPI-VM), you'll need to follow step 1 & 2 of 

----> https://randomnerdtutorials.com/esp32-cam-post-image-photo-server/

 (manual install of phpmyadmin might be needed.)
 --> http://192.168.x.x/gallery.php is the location you will find your pictures.
 

--> doorbell case STL: https://www.thingiverse.com/thing:4602738



Thanks Reddit/r/esp32
