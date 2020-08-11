IBusBM IBus;

void rcInit() {
	IBus.begin(Serial);
}

// reads a channel of the reciever
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
	uint16_t ch = IBus.readChannel(channelInput);
	if (ch < 100) return defaultValue;
	return map(ch, 1000, 2000, minLimit, maxLimit);
}