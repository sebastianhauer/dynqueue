# A Dynamic Queue in C++

## Build Prerequisites

To build this project, the following tools need to be installed:

1. **C++ Compiler**: A modern C++ compiler that supports C++20 is necessary.
   GCC or Clang are suitable options.
1. **CMake**: This project uses CMake for its build system. CMake version 3.26
   or higher is required. It can be downloaded from the
   [official website](https://cmake.org/download/).
1. **Ninja**: This project relies on Ninja as the build backend. It can be
   downloaded from the [official website](https://ninja-build.org/).

## Building with CMake and Presets

After installing the prerequisites, the project can be built using CMake. This
project supplies CMake presets in the `CMakePresets.json` file for convenience.
These presets are preconfigured for both `clang` and `gcc`, and for both
`debug` and `release` builds. The output from the build process will be
directed to `out/build/${presetName}`.

### Presets

To see all preset for both configure and build time simply run from within the
project directory:

```shell
cmake --list-presets=configure && cmake --list-presets=build
```

### Configure

To configure the build system with `gcc` for a `debug` build, run:

```shell
cmake --preset=unix-gcc-debug
```

### Build

After configuration, the system can be built using the following command:

```shell
cmake --build --preset=unix-gcc-debug -j 8
```

The `-j` option specifies the number of jobs (i.e., commands) to run
simultaneously. Adjust this value according to the system's capabilities to
optimize the parallel compilation process.
