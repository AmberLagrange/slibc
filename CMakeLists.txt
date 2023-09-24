cmake_minimum_required(VERSION 3.24.2)

project(slibc VERSION 1.0.1 DESCRIPTION "Educational C Standard Library Project")
include(GNUInstallDirs)

add_library(slibc SHARED
    stdlib/stdio.c
    stdlib/stdlib.c
    stdlib/string.c
    stdlib/syscall.c
)

set_target_properties(slibc PROPERTIES
    C_STANDARD 90
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER
        include/stdarg.h
        include/stdio.h
        include/stdlib.h
        include/string.h
        include/syscall.h
)

configure_file(slibc.pc.in slibc.pc @ONLY)

install(TARGETS slibc
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/slibc.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)