cmake_minimum_required(VERSION 3.24.2)
project(slibc_tests)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SHATTER_LIBC            REQUIRED slibc)
pkg_check_modules(SHATTER_LIBC_START_MAIN REQUIRED slibc_start_main)

execute_process(
    COMMAND pkg-config slibc --libs
    OUTPUT_VARIABLE SHATTER_LIBC_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND pkg-config slibc_start_main --libs
    OUTPUT_VARIABLE SHATTER_LIBC_START_MAIN_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SHATTER_LIBC_LIBS} ${SHATTER_LIBC_START_MAIN_LIBS}")

add_executable(slibc_tests
    src/tests.c
    src/ctype_tests.c
    src/stdio_tests.c
    src/stdlib_tests.c
    src/string_tests.c)


target_compile_options(slibc_tests PRIVATE ${SHATTER_LIBC_CFLAGS} ${SHATTER_LIBC_START_MAIN_CFLAGS} -Wall -Wextra -Wpedantic -Werror)
set_target_properties(slibc_tests PROPERTIES
    C_STANDARD 90
    C_EXTENSIONS OFF
    OUTPUT_NAME tests
)

target_link_directories(slibc_tests PRIVATE ${SHATTER_LIBC_LIBRARY_DIRS} ${SHATTER_LIBC_START_MAIN_LIBRARY_DIRS})
target_include_directories(slibc_tests PRIVATE ${SHATTER_LIBC_INCLUDE_DIRS})
target_link_libraries(slibc_tests PRIVATE ${SHATTER_LIBC_LIBRARIES} ${SHATTER_LIBC_START_MAIN_LIBRARIES})
