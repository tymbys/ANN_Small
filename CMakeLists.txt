project(ANN_Small)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_BUILD_TYPE Debug)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")

file(GLOB SRC_LIST "./*.c" )
#file(GLOBRECURSE SRC_LIST "*.c")

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} -lm)

