cmake_minimum_required(VERSION 3.24.2)
project(test)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SHATTER_LIBC REQUIRED slibc)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

add_executable(test_prog src/main.c ${CMAKE_SOURCE_DIR}/slibc/stdlib/start_main.c)

include_directories(${CMAKE_SOURCE_DIR}/slibc/include)

target_link_libraries(test_prog ${SHATTER_LIBC_LIBRARIES})
target_include_directories(test_prog PUBLIC ${SHATTER_LIBC_LIBRARIES})