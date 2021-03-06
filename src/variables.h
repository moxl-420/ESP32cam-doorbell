//------------------------------------------------------------------------------------------------------------
// Written by moxl
// Adapt chime.h   to change the sound produced by the speaker
// Adapt config.h  to change the user parameters
//------------------------------------------------------------------------------------------------------------


//   !!! DONT TOUCH THESE !!!

//needed for wifi
WiFiClient client;

// Global variables
int buttonState = 0;  
unsigned long previousMillis = 0;   // last time image was sent  
unsigned long previousMillisButton = 0;   // last time button was pressed.
unsigned long lastPressedButton = 0;    // last time button was pressed before previousMillisButton

//CPU CORES
static int taskCore = 0;
static int appCore = 1;

#define CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22
