#include <CapacitiveSensor.h>

CapacitiveSensor cap6_4 = CapacitiveSensor(3, 2);
CapacitiveSensor cap12_10 = CapacitiveSensor(7, 6);
int LED_Y = 9, LED_G = 10, BUZZER = 11;

void setup() {
  pinMode(LED_Y,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long total1 =  cap6_4.capacitiveSensor(30);
  long total2 =  cap12_10.capacitiveSensor(30);
  total1 = map(total1, 200, 220000, 0, 255);
  total2 = map(total2, 200, 60000, 0, 255);
  
  analogWrite(LED_Y, total1);
  analogWrite(LED_G, total2);
  analogWrite(BUZZER, (total1 + total2)/2);

  Serial.print(total1);
  Serial.print("\t");
  Serial.println(total2);
  delay(10);
}
