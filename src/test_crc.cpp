#include "mtest_can_crc.h"

int32_t start(const char *name)
{
	return 1;
}

int32_t addcrc(const char *name, uint32_t id, uint8_t *data, uint8_t datalen, int32_t *signaldata)
{
	if (datalen < 2)
	{
		return -1;
	}
	data[0] = 1;
	data[1] = 2;
	
	signaldata[0] = 10;	//counter startbit
	signaldata[1] = 11;	//counter value
	signaldata[2] = 12;	//crc startbit
	signaldata[3] = 13;	//crc value
	return 0;
}

int32_t stop(const char *name)
{
	return 1;
}