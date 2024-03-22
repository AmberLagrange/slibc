cmake_minimum_required(VERSION 3.24.2)

project(shatter-libc VERSION 0.0.1 DESCRIPTION "Educational C Standard Library Project")
include(GNUInstallDirs)

set(CMAKE_C_CLANG_TIDY clang-tidy)

configure_file(slibc.pc.in slibc.pc @ONLY)

add_library(slibc SHARED
    src/ctype/ctype.c

    src/mman/mmap.c
    src/mman/munmap.c

    src/signal/signal.c

    src/stdio/direct_io.c
    src/stdio/error_handling.c
    src/stdio/file_access.c
    src/stdio/file_operations.c
    src/stdio/file_positioning.c
    src/stdio/formatted_io.c
    src/stdio/put_internal.c
    src/stdio/stdio.c
    src/stdio/unformatted_io.c

    src/stdlib/convert.c
    src/stdlib/malloc.c
    src/stdlib/stdlib.c

    src/string/char_array_manip.c
    src/string/misc.c
    src/string/string_exam.c
    src/string/string_manip.c

    src/syscall/read.c
    src/syscall/syscall.c
    src/syscall/write.c

    src/utils/stack_chk_fail.c
)

set(SLIBC_HEADERS
    include/assert.h
    include/ctype.h
    include/signal.h
    include/stdarg.h
    include/stdio.h
    include/stdlib.h
    include/string.h
)

set_target_properties(slibc PROPERTIES
    C_STANDARD 90
    C_EXTENSIONS OFF
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "${SLIBC_HEADERS}"
    C_CLANG_TIDY "${CMAKE_C_CLANG_TIDY}"
)

target_compile_options(slibc PRIVATE -Wall -Wextra -Wpedantic -Werror -nostdinc)
target_link_options(slibc PRIVATE -nostdlib)

target_include_directories(slibc PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

install(FILES ${CMAKE_BINARY_DIR}/slibc.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(TARGETS slibc
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/slibc
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/slibc)

install(FILES ${CMAKE_SOURCE_DIR}/slibc.conf
    DESTINATION /etc/ld.so.conf.d)

install(CODE "execute_process(COMMAND ldconfig)")

add_custom_target(uninstall
    xargs rm < install_manifest.txt
    COMMAND ldconfig)

add_subdirectory(start_main)
