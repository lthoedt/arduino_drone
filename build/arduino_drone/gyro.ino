MPU6050 gyro(Wire);

float gyroStabiliseThreshold = 1.0;
float gyroStabiliseFactor = 1.0;

void gyroInit() {
	Wire.begin();
	gyro.begin();
	gyro.calcGyroOffsets(true);
}

void gyroUpdate() {
	gyro.update();

	gyroUpdateStabiliseFactor();
}

float gyroGetAngleX() {
	// forward is +
	// backward is -
	return gyro.getGyroAngleX();
}

float gyroGetAngleY() {
	// right is +
	// left is -
	return gyro.getGyroAngleY();
}

float gyroGetAngleZ() {
	// left is +
	// right is -
	return gyro.getGyroAngleZ();
}


void gyroStabilise() {
	// if ( !rcPitchInput() ) {
		gyroStabiliseX();
	// }

	// if ( !rcRollInput() ) {
		gyroStabiliseY();
	// }

	// if ( !rcRotateInput() ) {
	// 	gyroStabiliseZ();
	// }

}


void gyroStabiliseX() {
	float aX = gyroGetAngleX();

	if ( aX > gyroStabiliseThreshold || aX < -gyroStabiliseThreshold) {
		motorsX( gyroStabiliseFactor * aX );
	}
}

void gyroStabiliseY() {
	float aY = gyroGetAngleY();

	if ( aY > gyroStabiliseThreshold || aY < -gyroStabiliseThreshold) {
		motorsY( -gyroStabiliseFactor * aY );
	}
}

void gyroStabiliseZ() {
	float aZ = gyroGetAngleZ();

	motorsZ( gyroStabiliseFactor * aZ );
}

void gyroUpdateStabiliseFactor() {
	gyroStabiliseFactor = readChannel( 9, 0, 8, 1 );
}