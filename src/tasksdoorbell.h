#include "esp_camera.h"

void dingdong (void * pvParameters) {
        while(1){

            vTaskSuspend(NULL);
            //vTaskDelay(2000 / portTICK_RATE_MS);

            EasyBuzzer.singleBeep(
            659,   // Frequency in hertz(HZ).
            500   // Duration of the beep in milliseconds(ms).
            );
            vTaskDelay(500 / portTICK_RATE_MS);

            EasyBuzzer.singleBeep(
            523,   // Frequency in hertz(HZ).
            1000   // Duration of the beep in milliseconds(ms).
            );
            vTaskDelay(1000 / portTICK_RATE_MS);
            
            EasyBuzzer.singleBeep(
            659,   // Frequency in hertz(HZ).
            500   // Duration of the beep in milliseconds(ms).
            );
            vTaskDelay(500 / portTICK_RATE_MS);
            
            EasyBuzzer.singleBeep(
            523,   // Frequency in hertz(HZ).
            1000   // Duration of the beep in milliseconds(ms).
            );
            vTaskDelay(1000 / portTICK_RATE_MS);
            
            EasyBuzzer.singleBeep(
            659,   // Frequency in hertz(HZ).
            500   // Duration of the beep in milliseconds(ms).
            );
            vTaskDelay(500 / portTICK_RATE_MS);

            EasyBuzzer.singleBeep(
            523,   // Frequency in hertz(HZ).
            1000   // Duration of the beep in milliseconds(ms).
            );
            vTaskDelay(1000 / portTICK_RATE_MS);
            

            EasyBuzzer.stopBeep();
            digitalWrite(ledPin, LOW);
                              

            }           
    }

void picnow (void * pvParameters) {

        while(1){

vTaskSuspend(NULL);

String getAll;
String getBody;

  camera_fb_t * fb = NULL;
  fb = esp_camera_fb_get();
  if(!fb) {
    Serial.println("Camera capture failed");
    vTaskDelay(500 / portTICK_RATE_MS);
    ESP.restart();
    
  }
 
  Serial.println("Connecting to server: " + serverName);

  if (client.connect(serverName.c_str(), serverPort)) {
    Serial.println("Connection successful!");    
    String head = "--Moxl doorbell thanks to RandomNerdTutorials\r\nContent-Disposition: form-data; name=\"imageFile\"; filename=\"esp32-cam.jpg\"\r\nContent-Type: image/jpeg\r\n\r\n";
    String tail = "\r\n--Moxl doorbell thanks to RandomNerdTutorials--\r\n";

    uint16_t imageLen = fb->len;
    uint16_t extraLen = head.length() + tail.length();
    uint16_t totalLen = imageLen + extraLen;
  
    client.println("POST " + serverPath + " HTTP/1.1");
    client.println("Host: " + serverName);
    client.println("Content-Length: " + String(totalLen));
    client.println("Content-Type: multipart/form-data; boundary=RandomNerdTutorials");
    client.println();
    client.print(head);
  
    uint8_t *fbBuf = fb->buf;
    size_t fbLen = fb->len;
    for (size_t n=0; n<fbLen; n=n+1024) {
      if (n+1024 < fbLen) {
        client.write(fbBuf, 1024);
        fbBuf += 1024;
      }
      else if (fbLen%1024>0) {
        size_t remainder = fbLen%1024;
        client.write(fbBuf, remainder);
      }
    }   
    client.print(tail);
    
    esp_camera_fb_return(fb);
    
    int timoutTimer = 5000;
    long startTimer = millis();
    boolean state = false;
    
    while ((startTimer + timoutTimer) > millis()) {
      Serial.print(".");
      delay(100);      
      while (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (getAll.length()==0) { state=true; }
          getAll = "";
        }
        else if (c != '\r') { getAll += String(c); }
        if (state==true) { getBody += String(c); }
        startTimer = millis();
      }
      if (getBody.length()>0) { break; }
    }
    Serial.println();
    client.stop();
    Serial.println(getBody);
  }
  else {
    getBody = "Connection to " + serverName +  " failed.";
    Serial.println(getBody);
  }
 




             }           
    }