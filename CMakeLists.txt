cmake_minimum_required(VERSION 3.0.0)
project(crc VERSION 0.1.0)

if(WIN32)
    message(os is win32)
    #set(CMAKE_MFC_FLAG 1)
endif()

#include(CTest)
#enable_testing()

file(GLOB CRC_SOURCE src/*.cpp)
file(GLOB CRC_HEADER src/*.h)

add_library(crc SHARED ${CRC_SOURCE} ${CRC_HEADER} src/exports.def)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)