# mtest_can_crc

更改**mtest_can_crc.cpp**文件，完善addcrc函数，实现自定义的crc算法。

函数原型为：
`int32_t addcrc(const char *name, uint32_t id, uint8_t *data, uint8_t datalen, int32_t *signaldata);`

**MTest经过读取变量解析成数据后，准备发送前，调用此函数，由此函数更改校验数据后，发送到总线。**

其中：  
name:每个CAN通道都会有一个唯一的名称，表明这条添加校验的函数是哪个CAN通道调用的。  
id: CAN消息ID  
data: CAN消息的数据  
datalen: CAN消息的数据长度  
signaldata: 固定4个长度的数组，返回信号的起始位和值，用于写入MTest中的Counter和crc变量,分别为Counter StartBit，counter，crc StartBit，crc。MTest在得到数据后会更新Counter和CRC变量的值。  
return: 1表示成功，0表示失败

**一般编写流程为：根据源CAN消息数据，获取Counter，计算CRC，更改源数据消息插入计算的CRC，返回新的Counter，和计算出的CRC。**

### 使用VisualStudio编译

官方下载 : https://visualstudio.microsoft.com/zh-hans/vs/community/  
安装使用 : https://learn.microsoft.com/zh-cn/cpp/build/cmake-projects-in-visual-studio?view=msvc-170  


### 使用vscode编译  

官方下载 : https://code.visualstudio.com/  
GCC on Windows : https://code.visualstudio.com/docs/cpp/config-mingw  
GCC on Linux : https://code.visualstudio.com/docs/cpp/config-linux  
Developing in WSL : https://code.visualstudio.com/docs/remote/wsl  
CMake Tools : https://code.visualstudio.com/docs/cpp/cmake-linux  
msys2镜像站  : https://mirror.tuna.tsinghua.edu.cn/help/msys2/  
