#include "mtest_can_crc.h"
#include "tools.h"
#include "stdio.h"

int32_t start(const char *name)
{
	return 1;
}

int32_t addcrc(const char *name, uint32_t id, uint8_t *data, uint8_t dataLen, int32_t *signalData)
{
	if(id == 0)
	{
		if(dataLen < 8) return 0;
		uint8_t counter = data[6] & 0x0f; //low 4bit is counter
		uint8_t checkSum = calculate_crc_J1850(data, 7);
		data[7] = checkSum; //add checksum to data

		signalData[0] = 48;	//counter start bit
		signalData[1] = counter > 14 ? 0 : counter + 1;	//counter 0-15
		signalData[2] = 56;	//crc start bit
		signalData[3] = checkSum;	//crc value
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
	uint8_t crc = calculate_crc_J1850(test, 7);
	printf("checksum is :%d(0x%x)\n",crc,crc);
    crc = calculate_crc_1d(test, 7);
    printf("checksum is :%d(0x%x)\n",crc,crc);
    crc = calculate_crc8(test, 7, 0x1d);
    printf("checksum is :%d(0x%x)\n",crc,crc);
    printf("\n");

    crc = calculate_crc_2f(test, 7);
    printf("checksum is :%d(0x%x)\n",crc,crc);
    crc = calculate_crc8(test, 7, 0x2f);
    printf("checksum is :%d(0x%x)\n",crc,crc);

    //create_crc16_table(0x1021);
    //create_crc8_table(0x1d);
	return 1;
}