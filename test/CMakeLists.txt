cmake_minimum_required(VERSION 3.24.2)
project(test)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

add_executable(test src/main.c ${CMAKE_SOURCE_DIR}/slibc/stdlib/start_main.c)

include_directories(${CMAKE_SOURCE_DIR}/slibc/include)
target_link_libraries(test slibc)
