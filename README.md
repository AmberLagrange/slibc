[![License: MPL 2.0](https://img.shields.io/badge/License-MPL%202.0-brightgreen.svg)](https://opensource.org/licenses/MPL-2.0)

# Shatter Libc

Shatter Libc (slibc) is C89 compliant Standard Library written for educational purposes.
- [slibc](#shatter-libc)
- [Building](#building)
- [Running](#running)
- [Supported Platforms](#supported-platforms)

# Building

To build, simply run cmake with a desired directory, then run make install:

``` bash
$ cmake -S <source_directory> -B <build_directory>
$ make install
```

### Note:
``$ make install`` may require elevated permissions to install correctly.

# Running

slibc should be installed in your specified library path (``/usr/local/lib`` by default).

There is then a test program ``<build_directory>/test/test_prog`` which links with libslibc.so, which you can verify with
``ldd <build_directory>/test/test_prog``.

# Supported Platforms

Currently slibc only supports ``Linux x86_64``, but plans to supports ``x86`` and other ``Aarch64`` potentially in the future.

Other OSes will probably not be supported.