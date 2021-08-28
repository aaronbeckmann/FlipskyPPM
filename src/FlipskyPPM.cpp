/*
Flipsky Remote Reader Library
https://github.com/Chipney/FlipskyPPM

Aaron Beckmann 2021

License: GNU GPL v3
*/

#include "FlipskyPPM.h"
#include "Arduino.h"

FlipskyPPM::FlipskyPPM(int pin){
    pinMode(pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(pin), FlipskyPPM::handler, CHANGE);
}

void FlipskyPPM::handler(){
    static unsigned long previousTimestamp = 0;
    static unsigned long currentTimeStamp = 0;
    static unsigned long pulseWidth;
    
    currentTimeStamp = micros();
    pulseWidth = currentTimeStamp - previousTimestamp;
    previousTimestamp = currentTimeStamp;
    
    if (pulseWidth < 4000) {
        FlipskyPPM::value = pulseWidth - 1000;
    }
}

int FlipskyPPM::getNewestValue(){
    return this->value;
}

