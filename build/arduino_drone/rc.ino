IBusBM IBus;

int rcInputDeadzone = 2;

void rcInit() {
	IBus.begin(Serial);
}

boolean rcPitchInput() {
	return readChannel(1, 1000, 2000, 1000) > 1500 + rcInputDeadzone || readChannel(1, 1000, 2000, 1000) < 1500 - rcInputDeadzone;
}

boolean rcRollInput() {
	return readChannel(0, 1000, 2000, 1000) > 1500 + rcInputDeadzone || readChannel(0, 1000, 2000, 1000) < 1500 - rcInputDeadzone;
}

boolean rcRotateInput() {
	return readChannel(3, 1000, 2000, 1000) > 1500 + rcInputDeadzone || readChannel(3, 1000, 2000, 1000) < 1500 - rcInputDeadzone;
}

boolean rcEmergencyStop() {
	int emergencySwitch = readChannel( 4, 0, 1, 1 );
	if ( emergencySwitch == 1 ) {
		motorsStop();
		motorsTurn();
	}
	return emergencySwitch;
}

// reads a channel of the reciever
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
	uint16_t ch = IBus.readChannel(channelInput);
	if (ch < 100) return defaultValue;
	return map(ch, 1000, 2000, minLimit, maxLimit);
}