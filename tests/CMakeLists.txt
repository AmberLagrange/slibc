cmake_minimum_required(VERSION 3.24.2)

project(slibc_tests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SHATTER_LIBC REQUIRED slibc)

execute_process(
    COMMAND pkg-config slibc --libs
    OUTPUT_VARIABLE SHATTER_LIBC_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SHATTER_LIBC_TLIBS}")

enable_testing()

add_executable(tests src/tests.cc
                     src/ctype_tests.cc)


target_compile_options(tests PRIVATE ${SHATTER_LIBC_TCFLAGS} -Wall -Wextra -Wpedantic -Werror)

target_link_directories(tests PRIVATE ${SHATTER_LIBC_LIBRARY_DIRS})
target_link_libraries(tests GTest::gtest_main ${SHATTER_LIBC_LIBRARIES})

include(GoogleTest)
gtest_discover_tests(tests)
