
//------------------------------------------------------------------------------------------------------------
// Written by moxl
// Adapt chime.h   to change the sound produced by the speaker
// Adapt config.h  to change the user parameters
//------------------------------------------------------------------------------------------------------------


//Notes to HZ
// !!! Dont change these !!!
// Changing these will NOT adjust volume, only the tonepitch.
const int NOOT_E = 659;
const int NOOT_C = 523;
const int NOOT_D = 587;
const int NOOT_G = 783;


// fill in total duration of song, or will only last songlength as declared here
unsigned long songlength = 8000; 

// procedure used make the sound by using PWN signals.
// Use the notes provided trigger each note and adjust the time.
void chimechomechime(){

        //length of the notes - Change not required
        unsigned long notems[] = {500, 1000, 1500};    
        unsigned long songtiming = 0;
        unsigned long timenow = millis () ;
        int nootcount = 1;
        
        while (millis () - timenow < songlength){

        if (millis() == timenow + songtiming && nootcount == 1){
            EasyBuzzer.singleBeep(
            NOOT_E,   // Frequency in hertz(HZ).
            notems[0]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[0];
            nootcount = nootcount + 1;
            }
    
        if (millis() == timenow + songtiming && nootcount == 2){
            EasyBuzzer.singleBeep(
            NOOT_C,   // Frequency in hertz(HZ).
            notems[2]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[2];
            nootcount = nootcount + 1;
            }

        if (millis() == timenow + songtiming && nootcount == 3){
            EasyBuzzer.singleBeep(
            NOOT_D,   // Frequency in hertz(HZ).
            notems[1]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[1];
            nootcount = nootcount + 1;
            }

        if (millis() == timenow + songtiming && nootcount == 4){
            EasyBuzzer.singleBeep(
            NOOT_G,   // Frequency in hertz(HZ).
            notems[1]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[1];
            nootcount = nootcount + 1;
            }

        if (millis() == timenow + songtiming && nootcount == 5){
            EasyBuzzer.singleBeep(
            NOOT_C,   // Frequency in hertz(HZ).
            notems[1]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[1];
            nootcount = nootcount + 1;
            }

        if (millis() == timenow + songtiming && nootcount == 6){
            EasyBuzzer.singleBeep(
            NOOT_G,   // Frequency in hertz(HZ).
            notems[1]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[1];
            nootcount = nootcount + 1;
            }

        if (millis() == timenow + songtiming && nootcount == 7){
            EasyBuzzer.singleBeep(
            NOOT_C,   // Frequency in hertz(HZ).
            notems[0]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[0];
            nootcount = nootcount + 1;
            }

        if (millis() == timenow + songtiming && nootcount == 8){
            EasyBuzzer.singleBeep(
            NOOT_D,   // Frequency in hertz(HZ).
            notems[0]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[0];
            nootcount = nootcount + 1;
            }
    
        if (millis() == timenow + songtiming && nootcount == 9){
            EasyBuzzer.singleBeep(
            NOOT_E,   // Frequency in hertz(HZ).
            notems[0]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[0];
            nootcount = nootcount + 1;
            }

        if (millis() == timenow + songtiming && nootcount == 10){
            EasyBuzzer.singleBeep(
            NOOT_C,   // Frequency in hertz(HZ).
            notems[0]   // Duration of the beep in milliseconds(ms).
            );
            songtiming = songtiming + notems[0];
            nootcount = nootcount + 1;
            }

    //end of while
        }
    EasyBuzzer.stopBeep();
    
    //end of procedure
}

