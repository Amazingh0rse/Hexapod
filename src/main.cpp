#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const String SPEED = "T100";
const String SPEED2 = "T500";
const int ITERATION_COUNT = 5;
int iteration = 0;

const char *ssid = "nodemcu";
const char *pass = "nodemcupassword69";
ESP8266WebServer server(80);
String html = "<!DOCTYPE html><html><head><title>Robocontrollerl</title></head><body><h1>Robocontroller</h1><a href=\"forward\"><button >forward</button></a><br><a href=\"left\"><button>left</button></a><a href=\"right\"><button>right</button></a></body></html>";

bool doWalk = false;
bool doLeft = false;
bool doRight = false;
bool hasReset = false;
bool walkStepCheck [6] = {false,false,false,false,false,false};
bool rotationStepCheck [6] = {false,false,false,false,false,false};
unsigned long startTime = 0;
unsigned long DELAY = 500;

void walkCycle() {
  if(!hasReset) {
    Serial.println("#1P1500#2P1400#3P2000#4P1500#5P1500#6P1250#7P2000#8P1500#9P1500#10P1250#11P2000#12P1500#13P1500#14P1500#15P1000#16P1500#17P1500#18P1500#19P1000#20P1500#21P1500#22P1700#23P1000#24P1500#25P1500#26P1500#27P1500#28P1500#29P1500#30P1500#31P1500#32P1500"+SPEED+"D500");
    hasReset = true;
    startTime = millis();
  }
  unsigned long timeSinceStart = millis() - startTime;

  if(timeSinceStart >= DELAY && !walkStepCheck[0]) {
    Serial.println("#1P1800#2P1700#3P2000#6P1250#7P2000#10P1250#11P2000#13P1200#14P1200#15P1000#19P1000#22P1700#23P1000"+SPEED+"D500");
    walkStepCheck[0] = true;
  }

  if(timeSinceStart >= DELAY*2 && !walkStepCheck[1]) {
    Serial.println("#2P1400#14P1550#15P1100"+SPEED+"D500");
    walkStepCheck[1] = true;
  }

  if(timeSinceStart >= DELAY*3 && !walkStepCheck[2]) {
    Serial.println("#6P1600#7P2250#18P1300#19P1200"+SPEED+"D500");
    walkStepCheck[2] = true;
  }

  if(timeSinceStart >= DELAY*4 && !walkStepCheck[3]) {
    Serial.println("#6P1400#18P1600"+SPEED+"D500");
    walkStepCheck[3] = true;
  }

  if(timeSinceStart >= DELAY*5 && !walkStepCheck[4]) {
    Serial.println("#9P1200#10P1550#21P1700#22P1400"+SPEED+"D500");
    walkStepCheck[4] = true;
  }

  if(timeSinceStart >= DELAY*6 && !walkStepCheck[5]) {
    Serial.println("#10P1250#22P1800#23P1100"+SPEED+"D500");
    walkStepCheck[5] = true;
  }

  if(timeSinceStart >= DELAY*7) {
    Serial.println("#1P1500#6P1250#7P2000#9P1500#13P1500#14P1500#15P1000#18P1500#19P1000#21P1500#22P1700#23P1000"+SPEED2+"D500");
    ++iteration;
    if(iteration >= ITERATION_COUNT) {
      iteration = 0;
      doWalk = false;
    }
    hasReset = false;
    for(int i = 0; i < 6; ++i) {
      walkStepCheck[i] = false;
    }
  }
}

void leftRotationCycle() {
  if(!hasReset) {
    Serial.println("#1P1500#2P1400#3P2000#4P1500#5P1550#6P1250#7P2000#8P1500#9P1500#10P1250#11P2000#12P1500#13P1500#14P1500#15P1000#16P1500#17P1450#18P1500#19P1000#20P1500#21P1500#22P1700#23P1000#24P1500#25P1500#26P1500#27P1500#28P1500#29P1500#30P1500#31P1500#32P1500"+SPEED+"D500");
    hasReset = true;
    startTime = millis();
  }
  unsigned long timeSinceStart = millis() - startTime;

  if(timeSinceStart >= DELAY && !rotationStepCheck[0]) {
    Serial.println("#1P1200#2P1700#13P1200#14P1200"+SPEED+"D500");
    rotationStepCheck[0] = true;
  }

  if(timeSinceStart >= DELAY*2 && !rotationStepCheck[1]) {
    Serial.println("#2P1400#14P1500"+SPEED+"D500");
    rotationStepCheck[1] = true;
  }

  if(timeSinceStart >= DELAY*3 && !rotationStepCheck[2]) {
    Serial.println("#9P1200#10P1550#21P1300#22P1400"+SPEED+"D500");
    rotationStepCheck[2] = true;
  }

  if(timeSinceStart >= DELAY*4 && !rotationStepCheck[3]) {
    Serial.println("#10P1250#22P1700"+SPEED+"D500");
    rotationStepCheck[3] = true;
  }

  if(timeSinceStart >= DELAY*5 && !rotationStepCheck[4]) {
    Serial.println("#5P1250#6P1550#17P1150#18P1200"+SPEED+"D500");
    rotationStepCheck[4] = true;
  }

  if(timeSinceStart >= DELAY*6 && !rotationStepCheck[5]) {
    Serial.println("#6P1250#18P1500"+SPEED+"D500");
    rotationStepCheck[5] = true;
  }

  if(timeSinceStart >= DELAY*7) {
    Serial.println("#1P1500#5P1550#9P1500#13P1500#17P1450#21P1500"+SPEED+"D500");
    ++iteration;
    if(iteration >= ITERATION_COUNT) {
      iteration = 0;
      doLeft = false;
    }

    hasReset = false;
    for(int i = 0; i < 6; ++i) {
      rotationStepCheck[i] = false;
    }
  }
}

void rightRotationCycle() {
  if(!hasReset) {
    Serial.println("#1P1500#2P1400#3P2000#4P1500#5P1550#6P1250#7P2000#8P1500#9P1500#10P1250#11P2000#12P1500#13P1500#14P1500#15P1000#16P1500#17P1450#18P1500#19P1000#20P1500#21P1500#22P1700#23P1000#24P1500#25P1500#26P1500#27P1500#28P1500#29P1500#30P1500#31P1500#32P1500"+SPEED+"D500");
    hasReset = true;
    startTime = millis();
  }
  unsigned long timeSinceStart = millis() - startTime;

  if(timeSinceStart >= DELAY && !rotationStepCheck[0]) {
    Serial.println("#1P1800#2P1700#13P1800#14P1200"+SPEED+"D500");
    rotationStepCheck[0] = true;
  }

  if(timeSinceStart >= DELAY*2 && !rotationStepCheck[1]) {
    Serial.println("#2P1400#14P1500"+SPEED+"D500");
    rotationStepCheck[1] = true;
  }

  if(timeSinceStart >= DELAY*3 && !rotationStepCheck[2]) {
    Serial.println("#9P1800#10P1550#21P1700#22P1400"+SPEED+"D500");
    rotationStepCheck[2] = true;
  }

  if(timeSinceStart >= DELAY*4 && !rotationStepCheck[3]) {
    Serial.println("#10P1250#22P1700"+SPEED+"D500");
    rotationStepCheck[3] = true;
  }

  if(timeSinceStart >= DELAY*5 && !rotationStepCheck[4]) {
    Serial.println("#5P1850#6P1550#17P1750#18P1200"+SPEED+"D500");
    rotationStepCheck[4] = true;
  }

  if(timeSinceStart >= DELAY*6 && !rotationStepCheck[5]) {
    Serial.println("#6P1250#18P1500"+SPEED+"D500");
    rotationStepCheck[5] = true;
  }

  if(timeSinceStart >= DELAY*7) {
    Serial.println("#1P1500#5P1550#9P1500#13P1200#17P1450#21P1500"+SPEED+"D500");
    ++iteration;
    if(iteration >= ITERATION_COUNT) {
      iteration = 0;
      doRight = false;
    }
    hasReset = false;
    for(int i = 0; i < 6; ++i) {
      rotationStepCheck[i] = false;
    }
  }
}



void handleRoot() {
  server.send(200,"text/html", html);
}

void handleWalk() {
  server.send(200,"text/html", html);
  doWalk = true;
}

void handleLeft() {
  server.send(200, "text/html", html);
  doLeft = true;
}

void handleRight() {
  server.send(200, "text/html", html);
  doRight = true;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  Serial.setDebugOutput(true);
  WiFi.softAP(ssid, pass);
  delay(5000);
  server.on("/", handleRoot);
  server.on("/forward", handleWalk);
  server.on("/left", handleLeft);
  server.on("/right", handleRight);
  server.begin();
}

void loop() {
  if(doWalk) {
    walkCycle();
  }
  if(doLeft) {
    leftRotationCycle();
  }
  if(doRight) {
  rightRotationCycle();
  }

  server.handleClient();
}