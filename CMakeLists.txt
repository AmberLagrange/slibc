cmake_minimum_required(VERSION 3.24.2)
project(Shatter_LIBC)

add_subdirectory(slibc)
add_subdirectory(test)

configure_file(slibc.pc.in slibc.pc @ONLY)
