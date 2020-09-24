#include <esp32cam.h>
#include <WiFiClient.h>
#include "ESP32_FTPClient.h"

 
 #define FTP_BUF_SIZE 4096 //512   //  700 KByte/s download in AP mode, direct connection.

//------------------------------------------------------------------------------------------------------------
// Written by moxl
// Adapt chime.h   to change the sound produced by the speaker
// Adapt config.h  to change the user parameters
//------------------------------------------------------------------------------------------------------------


//   !!! DONT TOUCH THESE !!!

void ftp_makedir(){
  // Make a new directory
  ftp.OpenConnection();
  ftp.InitFile("Type A");
  ftp.MakeDir("/FTP/camera");
  ftp.CloseConnection();
  }

void ftp_thepicsend(){
  // Create the new file and send the image
  ftp.OpenConnection();
  ftp.ChangeWorkDir("/FTP/camera");
  ftp.InitFile("Type I");
  ftp.NewFile("octocat.jpg");
  ftp.WriteData( octocat_pic, sizeof(octocat_pic) );
  ftp.CloseFile();
  ftp.CloseConnection();
  }




void ftp_Camerasend(){

char buf[FTP_BUF_SIZE];       // data buffer for transfers
  
  // take camera picture and send the image

  ftp.OpenConnection();
  ftp.ChangeWorkDir("/FTP/camera");
  ftp.InitFile("Type I");
  ftp.NewFile("campic.jpg");
  ftp.WriteClientBuffered(WiFiClient, client, sizeof(FTP_BUF_SIZE) );
  ftp.CloseFile();
  ftp.CloseConnection();
  }

void ftp_maketxt(){
  // Create the file new and write a string into it
  ftp.OpenConnection();
  ftp.InitFile("Type A");
  ftp.NewFile("hello_world.txt");
  ftp.Write("Hello World");
  ftp.CloseFile();
  ftp.CloseConnection();
  }
  