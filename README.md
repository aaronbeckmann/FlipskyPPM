# FlipskyPPM

This library reads and decodes a Flipsky Reciever (PPM) Signal and decodes it correctly. 

* Uses an interrupt pin to read the signal => non-blocking, delay-friendly

## Limitations

* It uses `micros`, so any code that alters `Timer0` and breaks `micros` function, will also break this code

## Installation

1. Download from GitHub as ZIP
1. Using **Arduino IDE** use `Sketch` -> `Include Library` -> `Add .ZIP Library` and select downloaded ZIP

## Usage

On Arduino Nano with a Flipsky Remote signal attached to pin 2 (interrupt 0), example usage that prints PPM value over the serial port will look like this:

```
#include "FlipskyPPM.h"

FlipskyPPM reciever(2);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.println(reciever.getNewestValue());
  delay(20); //Flipsky Remotes send new value every 20ms
}
```

## License

This code is licensed under _GNU GENERAL PUBLIC LICENSE Version 3_ and is inspired by [https://github.com/DzikuVx/PPMReader](https://github.com/DzikuVx/PPMReader)
