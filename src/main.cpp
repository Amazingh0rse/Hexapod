#include <Arduino.h>

String SPEED = "T100";
String SPEED2 = "T500";

long DELAY = 500;

void setup() {
  Serial.begin(9600);
  delay(50);
}

void walkCycle() {
  Serial.println("#1P1500#2P1400#3P2000#4P1500#5P1500#6P1250#7P2000#8P1500#9P1500#10P1250#11P2000#12P1500#13P1500#14P1500#15P1000#16P1500#17P1500#18P1500#19P1000#20P1500#21P1500#22P1700#23P1000#24P1500#25P1500#26P1500#27P1500#28P1500#29P1500#30P1500#31P1500#32P1500"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#1P1800#2P1700#3P2000#6P1250#7P2000#10P1250#11P2000#13P1200#14P1200#15P1000#19P1000#22P1700#23P1000"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#2P1400#14P1550#15P1100"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#6P1600#7P2250#18P1300#19P1200"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#6P1400#18P1600"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#9P1200#10P1550#21P1700#22P1400"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#10P1250#22P1800#23P1100"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#1P1500#6P1250#7P2000#9P1500#13P1500#14P1500#15P1000#18P1500#19P1000#21P1500#22P1700#23P1000"+SPEED2+"D500");
  delay(DELAY);
}

void rotationCycle() {
  Serial.println("#1P1500#2P1400#3P2000#4P1500#5P1500#6P1250#7P2000#8P1500#9P1500#10P1250#11P2000#12P1500#13P1500#14P1500#15P1000#16P1500#17P1500#18P1500#19P1000#20P1500#21P1500#22P1700#23P1000#24P1500#25P1500#26P1500#27P1500#28P1500#29P1500#30P1500#31P1500#32P1500"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#1P1200#2P1700#13P1200#14P1200"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#2P1400#14P1500"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#9P1200#10P1550#21P1300#22P1400"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#10P1250#22P1700"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#5P1200#6P1550#17P1200#18P1200"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#6P1250#18P1500"+SPEED+"D500");
  delay(DELAY);
  Serial.println("#1P1500#5P1500#9P1500#13P1500#17P1500#21P1500"+SPEED+"D500");
  delay(DELAY);
}

void loop() {
  rotationCycle();
}