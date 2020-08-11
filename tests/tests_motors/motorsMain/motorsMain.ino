#include <Servo.h>
#include <IBusBM.h>

IBusBM IBus;


Servo motor_TL;
Servo motor_TR;
Servo motor_BL;
Servo motor_BR;

void setup() {
	IBus.begin(Serial);

	motor_TL.attach(3);
	motor_TR.attach(5);
	motor_BL.attach(6);
	motor_BR.attach(9);
}

void loop() {

	motor_TL.writeMicroseconds( readChannel( 2, 1000, 2000, 1000 ) );
	motor_TR.writeMicroseconds( readChannel( 2, 1000, 2000, 1000 ) );
	motor_BL.writeMicroseconds( readChannel( 2, 1000, 2000, 1000 ) );
	motor_BR.writeMicroseconds( readChannel( 2, 1000, 2000, 1000 ) );
}

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  uint16_t ch = IBus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
