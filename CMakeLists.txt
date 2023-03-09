cmake_minimum_required(VERSION 3.24)
project(Demo0)

set(CMAKE_CXX_STANDARD 23)
include_directories(inc)


aux_source_directory(src DIR_SRCS)

add_executable(${PROJECT_NAME} main.cpp ${DIR_SRCS})
#add_executable(${PROJECT_NAME} main.cpp)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(${PROJECT_NAME} ws2_32)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/TcAdsDll.lib)
#
#add_library(adslib STATIC src/Ads_Com.cpp inc/ADS)
#add_library(dplib STATIC src/Data_Process.cpp inc/Data_Process.h)
#add_library(mysocketlib STATIC src/mySocket.cpp inc/Mysocket.h)
#add_library(myThreadlib  STATIC src/myThreadfuc.cpp inc/myThreadfuc.h)
#add_library(sdlib STATIC src/Servo_Driver.cpp inc/Servo_Driver.h)
#add_library(tclib STATIC src/TimerCounter.cpp inc/TimerCounter.h)
#
#link_libraries(${PROJECT_NAME} PUBLIC dplib  adslib sdlib myThreadlib mysocketlib tclib)
#link_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/inc")
##add_executable(${PROJECT_NAME} main.cpp)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


