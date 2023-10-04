cmake_minimum_required(VERSION 3.24.2)

project(slibc VERSION 1.0.1 DESCRIPTION "Educational C Standard Library Project")
include(GNUInstallDirs)

configure_file(slibc.pc.in slibc.pc @ONLY)

add_library(slibc SHARED
    src/mman.c
    src/signal.c
    src/stdio.c
    src/stdlib.c
    src/string.c
    src/syscall.c
)

set(SLIBC_HEADERS include/assert.h include/signal.h include/stdarg.h include/stdio.h include/stdlib.h include/string.h)

set_target_properties(slibc PROPERTIES
    C_STANDARD 90
    C_EXTENSIONS OFF
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "${SLIBC_HEADERS}"
)

target_link_options(slibc 
    PUBLIC
        -nostdlib
)

target_compile_options(slibc PRIVATE -Wall -Wextra -Wpedantic -Werror)

install(FILES ${CMAKE_BINARY_DIR}/slibc.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(TARGETS slibc
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/slibc
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/slibc)

add_subdirectory(start_main)
