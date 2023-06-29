CPU Usage tracker

To configure with clang:

```bash
CC=clang cmake -S . -B build
```

To configure with gcc:

```bash
CC=gcc cmake -S . -B build
```

To build:

```bash
cmake --build build
```

To test (`--target` can be written as `-t` in CMake 3.15+):

```bash
cmake --build build --target test
```


The CMakeLists show off several useful design patterns for CMake.
