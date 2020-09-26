//------------------------------------------------------------------------------------------------------------
// Written by moxl
// Adapt chime.h   to change the sound produced by the speaker
// Adapt config.h  to change the user parameters
//------------------------------------------------------------------------------------------------------------

//set wifi credentials
const char* ssid = "SSID";
const char* password = "PASSWORD OF YOUR SSID";

//Howmuch time is allowed between two buttonpresses.
unsigned long ringTimeOut = 5000;   

//Declare pins
// These are best pins to use on AI-Thinker ESP32-CAM
// the number of the pushbutton pin
const int buttonPin = 12;     
// the number of the LED pin
const int ledPin =  13;      
// the number of the buzzer pin
const int buzzer = 15;       

//Set port of the webserver (default is port 80)
// not required to adapt.
const int serverPort = 80;

//Raspberry PI server IP
String serverName = "192.168.X.X";   // REPLACE WITH YOUR Raspberry Pi IP ADDRESS
String serverPath = "/upload.php";     // The default serverPath should be upload.php
const int timerInterval = 30000;    // time between each HTTP POST image (picture taken)
