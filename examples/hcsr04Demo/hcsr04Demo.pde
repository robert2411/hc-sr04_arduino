#include "hc-sr04.h"
Hcsr04 sensor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensor.Init(11,12);
}

void loop() {
  sensor.SendPuls();
  delay(5000);
  Serial.print(sensor.GetTime());
  Serial.print("-");
  Serial.println(sensor.GetDistence());
  // put your main code here, to run repeatedly: 
  
}
