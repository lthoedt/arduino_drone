#include <IBusBM.h>
#include <Servo.h>

IBusBM IBus;    // IBus object
Servo myservo;  // create servo object to control a servo

void setup() {

  Serial.begin(9600);
  
  IBus.begin(Serial);    // iBUS object connected to serial0 RX pin
  myservo.attach(9);     // attaches the servo on pin 9 to the servo object
  pinMode(4, OUTPUT);
}

void loop() {
  int val;
  val = IBus.readChannel(0); // get latest value for servo channel 1
  myservo.writeMicroseconds(val);   // sets the servo position

  if (readChannel(6, 0, 2, 0) == 1) {
    digitalWrite(4, HIGH); 
  } else {
    digitalWrite(4, LOW);
  }

}

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  uint16_t ch = IBus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
