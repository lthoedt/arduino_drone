#include <MPU6050_tockn.h>
#include <Wire.h>
#include <IBusBM.h>
#include <Servo.h>

void setup() {
	Serial.begin(9600);

	// ====== gyroscope ====== //
	gyroInit();
	// ====== ========= ====== //

	// ====== gyroscope ====== //
	rcInit();
	// ====== ========= ====== //

	// ====== motors ====== //
	motorsInit();
	// ====== ========= ====== //
}

void loop() {
	gyroUpdate();
	motorsUpdate();

}