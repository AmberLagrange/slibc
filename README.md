[![License: MPL 2.0](https://img.shields.io/badge/License-MPL%202.0-brightgreen.svg)](https://opensource.org/licenses/MPL-2.0)

# Shatter Libc

Shatter Libc (``slibc``) is C89 compliant Standard Library written for educational purposes.
- [slibc](#shatter-libc)
- [Building](#building)
- [Installing](#installing)
- [Running](#running)
- [Supported Platforms](#supported-platforms)

# Building

To build, simply run ``cmake`` in a build directory, then run ``make``

``` bash
$ cd slibc
$ mkdir build
$ cd build
$ cmake -S .. -B .
$ make
```

# Installing

To install ``slibc``, you can run the ``install`` target

``` bash
$ make install
```

This will install the library and header files onto your system default is (``/usr/local/lib/slibc`` and ``/usr/local/include/slibc`` by default).

To uninstall ``slibc``, you can either run
``` bash
$ make uninstall
```

or manually uninstall the files described in ``install_manifest.txt``, which is what ``make uninstall`` does by default.

### Note:

``make install`` and ``make uninstall`` may require elevated permissions to run correctly.

# Running

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

# Supported Platforms

Currently slibc only supports ``Linux x86_64``, but plans to supports ``x86`` and maybe ``Aarch64`` potentially in the future.

Other OSes will probably not be supported.