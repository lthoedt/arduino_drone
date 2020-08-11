Servo motor_TL;
Servo motor_TR;
Servo motor_BL;
Servo motor_BR;

int motor_TL_rpm;
int motor_TR_rpm;
int motor_BL_rpm;
int motor_BR_rpm;

int motor_manouvre_range;

void motorsInit() {
	motor_TL.attach(3);
	motor_TR.attach(5);
	motor_BL.attach(6);
	motor_BR.attach(9);
}

void motorsUpdate() {
	motorsUpdateManouvreRange();
	
	motorsUpdateThrottle();
	motorsUpdatePitch();
	motorsUpdateRoll();
	motorsUpdateRotate();

	gyroStabilise();
}

void motorsTurn() {
	motor_TL.writeMicroseconds( motor_TL_rpm );
	motor_TR.writeMicroseconds( motor_TR_rpm );
	motor_BL.writeMicroseconds( motor_BL_rpm );
	motor_BR.writeMicroseconds( motor_BR_rpm );
}

void motorsUpdateThrottle() {
	motor_TL_rpm = readChannel( 2, 1000, 2000, 1000 );
	motor_TR_rpm = readChannel( 2, 1000, 2000, 1000 );
	motor_BL_rpm = readChannel( 2, 1000, 2000, 1000 );
	motor_BR_rpm = readChannel( 2, 1000, 2000, 1000 );
}

void motorsUpdatePitch() {
	motorsX( readChannel( 1, -motor_manouvre_range, motor_manouvre_range, 0 ) );
}

void motorsUpdateRoll() {
	motorsY( readChannel( 0, -motor_manouvre_range, motor_manouvre_range, 0 ) );
}

void motorsUpdateRotate() {
	motorsZ( readChannel( 3, -motor_manouvre_range, motor_manouvre_range, 0 ) );
}

void motorsX( int speed ) {
	motor_TL_rpm -= speed;
	motor_TR_rpm -= speed;
	motor_BL_rpm += speed;
	motor_BR_rpm += speed;
}

void motorsY( int speed ) {
	motor_TL_rpm += speed;
	motor_TR_rpm -= speed;
	motor_BL_rpm += speed;
	motor_BR_rpm -= speed;
}

void motorsZ( int speed ) {
	motor_TL_rpm -= speed;
	motor_TR_rpm += speed;
	motor_BL_rpm += speed;
	motor_BR_rpm -= speed;
}

void motorsUpdateManouvreRange() {
	motor_manouvre_range = readChannel( 8, 10, 200, 40 );
}



