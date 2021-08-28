/*
Flipsky Remote Reader Library
https://github.com/Chipney/FlipskyPPM

Aaron Beckmann 2021

License: GNU GPL v3
*/

#ifndef FlipskyPPM_h
#define FlipskyPPM_h

#include "Arduino.h"

class FlipskyPPM{
  private:
    static void handler();
    volatile static int value;
  public:
    FlipskyPPM(int pin);
    int getNewestValue();
};

#endif