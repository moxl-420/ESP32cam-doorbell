# ESP32cam-doorbell
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
