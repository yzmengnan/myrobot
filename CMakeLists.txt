cmake_minimum_required(VERSION 3.24)
project(Demo0)
set(CMAKE_CXX_STANDARD 23)
include_directories(inc)


aux_source_directory(src DIR_SRCS)

add_executable(Demo0 demo0.cpp ${DIR_SRCS})
#add_executable(${PROJECT_NAME} main.cpp)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(${PROJECT_NAME} ws2_32)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/TcAdsDll.lib)


#add_executable( HELO hellotrial.cpp)


project(Demo1)

add_executable(Demo1 demo1.cpp ${DIR_SRCS})

target_link_libraries(Demo1 ws2_32)
target_link_libraries(Demo1 ${PROJECT_SOURCE_DIR}/lib/TcAdsDll.lib)