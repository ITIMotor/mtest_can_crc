/**
 * @file mtest_can_crc.h
 * @author Julles
 * @brief 用于MTest添加CAN通讯CRC校验，请不要更改此文件，必须按照此文件定义的参数实现
 * @version 1.0
 * @date 2022-06-10
 * 
 * @copyright ITIMotor Copyright (c) 2022
 * 
 */

#ifndef MTEST_CAN_CRC_H
#define MTEST_CAN_CRC_H


#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

/**
 * @brief CAN通道打开成功后会调用此命令
 *
 * @param name 每个CAN通道都会有一个唯一的名称
 * @return int32_t 1表示成功，0表示失败
 */
int32_t start(const char *name);

/**
 * @brief 每次发送一条CAN消息，都会调用此函数，需要在此函数中更改数据添加校验和计数器
 *
 * @param name 每个CAN通道都会有一个唯一的名称
 * @param id CAN消息ID
 * @param data CAN消息数据
 * @param dataLen CAN消息数据长度
 * @param signalData 返回信号的起始位和值，用于写入MTest中的Counter和crc变量，固定4个长度，分别为Counter StartBit，counter，crc StartBit，crc，默认-1为不写入
 * @return int32_t 1表示成功，0表示失败
 */
int32_t addcrc(const char *name, uint32_t id, uint8_t *data, uint8_t dataLen, int32_t *signalData);

/**
 * @brief CAN通道关闭后会调用此命令
 *
 * @param name 每个CAN通道都会有一个唯一的名称
 * @return int32_t 1表示成功，0表示失败
 */
int32_t stop(const char *name);

#ifdef __cplusplus
}
#endif

#endif //MTEST_CAN_CRC_H