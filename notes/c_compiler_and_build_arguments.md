# C Compiler and Build Arguments

## Compiler

We are using **GCC** through the MSYS2 **UCRT64** environment.

-   `gcc` --- GNU C compiler
-   `gdb` --- debugger
-   `make` --- build automation tool
-   `pacman` --- MSYS2 package manager

The compiler version and the C language standard are separate things.
For example, a GCC 15 compiler can compile code using the C17 language
standard.

## Basic compile command

``` cmd
gcc -std=c17 -Wall -Wextra -Wpedantic -pedantic-errors src/main.c -o build/main.exe
```

### Arguments

  -----------------------------------------------------------------------
  Argument                            Meaning
  ----------------------------------- -----------------------------------
  `-std=c17`                          Compile according to the C17
                                      language standard

  `-Wall`                             Enable a useful set of common
                                      warnings

  `-Wextra`                           Enable additional warnings

  `-Wpedantic`                        Warn about language extensions
                                      outside the selected standard

  `-pedantic-errors`                  Turn required diagnostics for
                                      non-conforming constructs into
                                      errors

  `src/main.c`                        Source file to compile

  `-o build/main.exe`                 Set the output executable path and
                                      name
  -----------------------------------------------------------------------

These options are supplied to GCC when building. GCC does not
automatically remember them for future compilations. A build script,
Makefile, or other build system can store and apply them consistently.

## Include directories

Use `-I` to tell GCC where to search for project header files.

``` cmd
gcc -std=c17 -Wall -Wextra -Wpedantic -pedantic-errors -Iinclude src/main.c src/variables.c -o build/main.exe
```

Here, `-Iinclude` adds the project's `include` directory to the header
search path.

## Compile and link separately

A C program can be built in stages:

``` cmd
gcc -c src/main.c -Iinclude -o build/main.o
gcc -c src/variables.c -Iinclude -o build/variables.o
gcc build/main.o build/variables.o -o build/main.exe
```

-   `-c` compiles a source file into an object file without linking an
    executable.
-   `.o` files contain compiled object code.
-   The final command links the object files into an executable.

For small exercises, compiling all source files in one command is
perfectly fine.

## Check the toolchain

In a new Windows CMD window:

``` cmd
gcc --version
where gcc
```

Inside the MSYS2 UCRT64 terminal:

``` bash
gcc --version
gdb --version
make --version
which gcc
gcc -dumpmachine
```

The GCC executable should resolve to the UCRT64 toolchain, typically
`C:\\msys64\\ucrt64\\bin\\gcc.exe` from Windows or `/ucrt64/bin/gcc`
inside MSYS2.

## Current project layout

``` text
c_practice/
├── src/
│   └── main.c
├── include/
├── build/
└── build.bat
```

-   `src/` --- C source files
-   `include/` --- project header files (`.h`)
-   `build/` --- generated executables and object files
-   `build.bat` --- stores the project's compiler command and flags

Keep generated build output separate from source code.
