MPU6050 mpu6050(Wire);

void gyroInit() {
	Wire.begin();
	mpu6050.begin();
	mpu6050.calcGyroOffsets(true);
}

void gyroUpdate() {
	mpu6050.update();

	// Serial.print( "X: " );
	// Serial.println( gyroGetAngleX() );

	// Serial.print( "Y: " );
	// Serial.println( gyroGetAngleY() );

	// Serial.print( "Z: " );
	// Serial.println( gyroGetAngleZ() );
}

float gyroGetAngleX() {
	return mpu6050.getAngleX();
}

float gyroGetAngleY() {
	return mpu6050.getAngleY();
}

float gyroGetAngleZ() {
	return mpu6050.getAngleZ();
}