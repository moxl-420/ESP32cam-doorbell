
#include <Arduino.h>
#include <EasyBuzzer.h>
#include <WiFi.h>
#include "config.h"
#include "variables.h"
#include "chime.h"
#include "camera.h"
#include "esp_camera.h"



//------------------------------------------------------------------------------------------------------------
// Written by moxl
// BaudRate: 115200
//
// Adapt chime.h   to change the sound produced by the speaker (Not required)
// Adapt config.h  to change the user parameters
//
// By Default pins  (change in config.h)
// Button = 12     (1K resistor pulled to ground)
// Led =  13       (you need a resistor if your led in the button doesn't come with one) 
// Buzzer = 15     (2n222 NPN with 1k resistor.)
// Wiring can be found https://www.thingiverse.com/thing:4602738
//
// For the LAMP server part on raspberry (or RPI-VM), you'll need to follow step 1 & 2 of 
//  ----> https://randomnerdtutorials.com/esp32-cam-post-image-photo-server/
//        (manual install of phpmyadmin might be needed.)
//  --> http://192.168.x.x/gallery.php is the location you will find your pictures.
// 
//  --> doorbell case STL: https://www.thingiverse.com/thing:4602738
//
//  Thanks Reddit/r/esp32
//------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------
//setup
//------------------------------------------------------------------------------------------------------------
void setup() {
  //Required
 
 Serial.begin(115200);
 Serial.println();


// set pins.
    pinMode (ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);

//set buzzerpin
    EasyBuzzer.setPin(buzzer);

  //start wifi
  WiFi.mode(WIFI_STA);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("ESP32-CAM IP Address: ");
  Serial.println(WiFi.localIP());
  // CAMERA_MODEL_AI_THINKER
// Pin Layout

  //camera config
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  // init with high specs to pre-allocate larger buffers
  if(psramFound()){
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 10;  //0-63 lower number means higher quality
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_CIF;
    config.jpeg_quality = 12;  //0-63 lower number means higher quality
    config.fb_count = 1;
  }
  
  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    delay(1000);
    ESP.restart();
  }

  


//-----------------------------------------------------------------------------------------------------
//end of setup
digitalWrite(ledPin, HIGH);
delay(1000);
Serial.println("-----------------------------------------------------------------------------------------------------");
Serial.println("Setup Completed, starting loop");
Serial.println("-----------------------------------------------------------------------------------------------------");
//-----------------------------------------------------------------------------------------------------
//end of setup
}
//-----------------------------------------------------------------------------------------------------
// loop
//-----------------------------------------------------------------------------------------------------
void loop() {
// Needed for buzzer to work, you delete, you no buzzer.
     EasyBuzzer.update();
// Needed for the webserver to handle clients.
     //server.handleClient();
// read the state of the pushbutton pin:
      buttonState = digitalRead(buttonPin);


// check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
        // Button is pressed.
          Serial.println("Button is pressed."); 
          digitalWrite(ledPin, HIGH); 
          sendPhoto(); 
          dingdong();
           ESP.restart();
           
 
          
  } else {
    // Button not pressed:
    digitalWrite(ledPin, LOW);
    
  }


//-----------------------------------------------------------------------------------------------------
//end of loop
}
//-----------------------------------------------------------------------------------------------------