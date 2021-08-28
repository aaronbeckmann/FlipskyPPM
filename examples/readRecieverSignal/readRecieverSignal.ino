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
