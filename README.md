[![License: MPL 2.0](https://img.shields.io/badge/License-MPL%202.0-brightgreen.svg)](https://opensource.org/licenses/MPL-2.0)

# Shatter Libc

Shatter Libc (``slibc``) is C89 compliant Standard Library written for educational purposes.

## Table of Contents
- [Shatter Libc](#shatter-libc)
- [Table of Contents](#table-of-contents)
- [Building](#building)
- [Installing](#installing)
- [Running](#running)
- [Tests](#tests)
- [Documentation](#documentation)
- [Supported Platforms](#supported-platforms)

## Building

To build, simply run ``cmake`` in a build directory, then run ``make``

``` bash
$ mkdir build
$ cd build
$ cmake -S .. -B .
$ make
```

## Installing

To install ``slibc``, you can run the ``install`` target.

``` bash
$ make install
```

This will install the library and header files onto your system (``/usr/local/lib/slibc`` and ``/usr/local/include/slibc`` by default).
It will also install a ``slibc.conf`` into ``/etc/ld.so.conf.d`` and run ``ldconfig``. 

To uninstall ``slibc``, you can either run
``` bash
$ make uninstall
```

or manually uninstall the files described in ``install_manifest.txt``, which is what ``make uninstall`` does by default.

### Note:

``make install`` and ``make uninstall`` may require elevated permissions to run correctly.

You may also need to set ``$PKG_CONFIG_PATH`` to the install directory of ``libslibc.pc`` and ``libslibc_start_main.pc`` (by default ``/usr/local/share/pkgconfig``).

## Running

There is an example program that can also be compiled and ran.

```bash
$ cd example
$ mkdir build
$ cd build
$ cmake -S .. -B .
$ make
$ ./example
```

This creates a program that is linked against ``slibc``, which can be verified with
```bash
$ ldd example
    linux-vdso.so.1 (...)
    libslibc.so.1 => <install_dir>/libslibc.so.1 (...)
```

If you wish to use ``slibc`` to build your own projects, be sure to not link against ``stdlib`` and to not use ``stdinc``.

Also ensure you include the header files for ``slibc`` and to dynamically link with ``libslibc.so`` and statically link with ``libslibc_start_main.a``.

An example command would be

```bash
$ $CC -std=c89 -nostdlib -nostdinc -I<include_dir> -L<lib_dir> -lslibc -lslibc_start_main foo.c -o foo
```

Alternatively, the provided ``CMakeLists.txt`` in the ``example`` directory provides a good starting point to build your own projects.

### Note

The ``execute_process`` is there to grab the ``LDFLAGS`` from pkg-config. Alternatively, you can instead have the following line

```bash
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")
```

to not link with ``stdlib``. The ``execute_process`` is there in the event additional linker flags are added.

## Tests

In the ``tests`` directory there is a series of tests using the [GoogleTest](https://github.com/google/googletest) framework. Testing these yourself is done similary to building and executing the example program.

```bash
$ cd tests
$ mkdir build
$ cd build
$ cmake -S .. -B .
$ make
$ ./tests
```
### Note

As the tests are in C++ and this is a C standard library, linking the programs in potentially override some C++ standard library code. If these symblols are not weak, this can lead to UB. Testing with clang++ appears to work for the time being. This may be fixed in the future.

## Documentation

``slibc`` also allows for the creation of documenation using  [doxygen](https://github.com/doxygen/doxygen). To do so, simply run ``doxygen`` in the build directory of ``slibc`` after running ``cmake``.

```bash
$ mkdir build
$ cd build
$ cmake -S .. -B .
$ doxygen
```

### Note

Documentation is not complete.

## Supported Platforms

Currently slibc only supports ``Linux x86_64``, but plans to supports ``x86``, and potentially ``Aarch64`` in the future.

Other OSes will most likely not be supported.