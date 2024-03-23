cmake_minimum_required(VERSION 3.24.2)

project(slibc_start_main VERSION 0.0.1 DESCRIPTION "Entry Point For slibc")
include(GNUInstallDirs)

configure_file(slibc_start_main.pc.in slibc_start_main.pc @ONLY)

add_library(slibc_start_main STATIC
    src/start_main.c
)

set_target_properties(slibc_start_main PROPERTIES
    C_STANDARD 90
    C_EXTENSIONS OFF
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    C_CLANG_TIDY "${CMAKE_C_CLANG_TIDY}"
)

target_compile_options(slibc_start_main PRIVATE -Wall -Wextra -Wpedantic -Werror -nostdinc)
target_link_options(slibc_start_main PUBLIC -nostdlib)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/slibc_start_main.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(TARGETS slibc_start_main
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/slibc)
