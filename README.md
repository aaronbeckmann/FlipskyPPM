# FlipskyPPM

This library reads and decodes a Flipsky Reciever (PPM) Signal and decodes it correctly. 

* Uses an interrupt pin to read the signal => non-blocking, delay-friendly
* Returns signal width in 10^-6s (similar to vesc-tools readings)

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

## Further details on the Flipsky Remote Signal

The value coming from the remote is encoded into a single ppm channel. Each 20ms a new value is sent.

```
                    approx. zero point
 |              |           |            |             |
 |   startbit   |         value          |    pause    |
 |     HIGH     |           |            |     LOW     |
0ms            1ms        1.4ms        1.8ms         19.8ms
```

The value itself is encoded in the width of "value" which is between 0ms (-100% throttle) and 1.8ms (+100% throttle). The Library returns the width of "value" in microseconds up to 3000*10^-6s, so that the user has some room to tweak the throttle percentage (discrepancies between models or even between hardware).

## License

This code is licensed under _GNU GENERAL PUBLIC LICENSE Version 3_ and is inspired by [https://github.com/DzikuVx/PPMReader](https://github.com/DzikuVx/PPMReader)
