cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 23)
include_directories(inc)

#aux_source_directory(src DIR_SRCS)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_library(comlib STATIC SRC/Ads_Com.cpp)
add_library(driverlib STATIC SRC/Servo_DRIVE.cpp)
add_library(dplib STATIC SRC/Data_Process.cpp)
add_library(mtlib STATIC SRC/myThreadfuc.cpp)
add_library(socketlib STATIC SRC/mySocket.cpp)
add_library(timecountlib STATIC SRC/TimerCounter.cpp)
add_library(datarecordlib STATIC src/Data_Record.cpp)
add_library(motion  STATIC src/motion.cpp)

project(Demo1)

add_executable(Demo1 demo1.cpp)

target_link_libraries(Demo1 comlib driverlib dplib mtlib socketlib timecountlib datarecordlib)
target_link_libraries(Demo1 ws2_32)
target_link_libraries(Demo1 motion)
target_link_libraries(Demo1 ${PROJECT_SOURCE_DIR}/lib/TcAdsDll.lib)