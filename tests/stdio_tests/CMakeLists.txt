cmake_minimum_required(VERSION 3.24.2)
project(stdio_tests)

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

enable_testing()

set(COMPILE_OPTIONS ${SHATTER_LIBC_CFLAGS} ${SHATTER_LIBC_START_MAIN_CFLAGS} -Wall -Wextra -Wpedantic -Werror)
set(TARGET_PROPERTIES C_STANDARD 90 C_EXTENSIONS OFF)
set(TARGET_LINK_DIRECTORIES ${SHATTER_LIBC_LIBRARY_DIRS} ${SHATTER_LIBC_START_MAIN_LIBRARY_DIRS})
set(TARGET_INCLUDE_DIRECTORIES ${SHATTER_LIBC_INCLUDE_DIRS})
set(TARGET_LINK_LIBRARIES ${SHATTER_LIBC_LIBRARIES} ${SHATTER_LIBC_START_MAIN_LIBRARIES})

add_executable              (test_stdio_printf_empty test_stdio_printf_empty.c)

target_compile_options      (test_stdio_printf_empty PRIVATE    ${COMPILE_OPTIONS})
set_target_properties       (test_stdio_printf_empty PROPERTIES ${TARGET_PROPERTIES})
target_link_directories     (test_stdio_printf_empty PRIVATE    ${TARGET_LINK_DIRECTORIES})
target_include_directories  (test_stdio_printf_empty PRIVATE    ${TARGET_INCLUDE_DIRECTORIES})
target_link_libraries       (test_stdio_printf_empty PRIVATE    ${TARGET_LINK_LIBRARIES})

add_test(test_stdio_printf_empty test_stdio_printf_empty)



add_executable              (test_stdio_printf_string_literal test_stdio_printf_string_literal.c)

target_compile_options      (test_stdio_printf_string_literal PRIVATE    ${COMPILE_OPTIONS})
set_target_properties       (test_stdio_printf_string_literal PROPERTIES ${TARGET_PROPERTIES})
target_link_directories     (test_stdio_printf_string_literal PRIVATE    ${TARGET_LINK_DIRECTORIES})
target_include_directories  (test_stdio_printf_string_literal PRIVATE    ${TARGET_INCLUDE_DIRECTORIES})
target_link_libraries       (test_stdio_printf_string_literal PRIVATE    ${TARGET_LINK_LIBRARIES})

add_test(test_stdio_printf_string_literal test_stdio_printf_string_literal)
