## Prerequisites
You need the following installed on your OS:
- C++ compiler
- C compiler
- CMAKE (minimum version 3.4.0)

If on Linux:
You need to be running in a graphical environment (i.e., X11/Wayland).

## Instructions
CMake will automatically take a look at your environment variables (what tools and libraries you have installed on your OS) and will implement things accordingly.
For example, if you've installed Doxygen, it can create Doxygen documentation. Or, if you've installed Visual Studio, a .sln file will be generated.

Run the following commands:

1. `mkdir build`
   This directory is where CMake will store the build files and executables to run.

2. `cd build`
   Change the current directory to the /build/ directory.

3. `cmake ..`
   This will point CMake to the source directory up one level. This will start compiling the program from the top level.

4. `cmake --build .`
   This will make CMake build the executables.

5. `cd Debug`
   Change the directory into the Debug folder. The executable will be there.

At this point, your current directory should be \game-source\build\Debug.

### If you are on Windows:
Open `GameLogic.exe`

### If you are on Linux:
Run the following command:
`./GameLogic`
