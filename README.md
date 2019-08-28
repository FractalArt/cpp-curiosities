# cpp-curiosities

A collection of some curious things I encountered in C++. 

***

## Compilation 

The examples can be compiled using the [meson][1] build system which is based on 
Python 3. It can be installed via 

```
$ pip3 install meson
```

To compile the examples create a build directory, configure and compile using 

```
$ mkdir build
$ cd build 
$ meson
$ ninja
```

This is, however, only for convenience. The examples are all in a single file so they can also be 
compiled by hand: 

```
$ cd src 
$ clang++ access_private.cpp
$ ./a.out
```

[1]: https://mesonbuild.com/ 
