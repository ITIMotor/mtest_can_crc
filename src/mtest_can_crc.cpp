#include "mtest_can_crc.h"
#include "tools.h"
#include "stdio.h"

int32_t start(const char *name)
{
	return 1;
}

int32_t addcrc(const char *name, uint32_t id, uint8_t *data, uint8_t datalen, int32_t *signaldata)
{
	if(false)
	{
		if(datalen < 8) return 0;
		uint8_t counter = data[6] & 0x0f; //low 4bit is counter
		uint8_t checkSum = CalculateCRC_J1850(data,7);
		data[7] = checkSum; //add checksum to data

		signaldata[0] = 48;	//counter startbit
		signaldata[1] = counter > 14 ? 0 : counter + 1;	//counter 0-15
		signaldata[2] = 56;	//crc startbit
		signaldata[3] = checkSum;	//crc value
		return 1;
	}
	return 0;
}

int32_t stop(const char *name)
{
	return 1;
}

int main()
{
	uint8_t test[] = {0,0,0x80,0,8,0,1,0};
	uint8_t crc = CalculateCRC_J1850(test,7);
	printf("checksum is :%d(0x%x)\n",crc,crc);
	return 1;
}