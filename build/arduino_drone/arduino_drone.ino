#include <MPU6050_tockn.h>
#include <Wire.h>
#include <IBusBM.h>
#include <Servo.h>
 
void setup() {
	Serial.begin(9600);

	// ====== gyroscope ====== //
	// gyroInit();
	// ====== ========= ====== //

	// ====== reciever ====== //
	rcInit();
	// ====== ========= ====== //

	// ====== motors ====== //
	motorsInit();
	// ====== ========= ====== //
}

void loop() {

	if ( !rcEmergencyStop() ) {
		// gyroUpdate();
		motorsUpdate();

		motorsTurn();
	}

}