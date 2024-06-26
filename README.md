# pawan-sutar-coding-challenge
Contains C++ code to solve ORNL coding challenge questions. 

## Requirements
- A compatible operating system (Linux, Mac or Windows).
- A compatible C++ compiler that supports at least C++17.
- CMake and a compatible build tool like make or Ninja for building the project.

## File Structure
- The project structure is kept simple to accomplish the task within given time frame.

      pawan-sutar-coding-challenge            # Project root
      |
      ├── CMakeLists.txt                      # Build system configuration
      |
      ├── utility.h                           # Function declarations
      |  
      ├── utility.cpp                         # Function definitions
      |  
      ├── utility_test.cpp                    # Unit tests

## Build Instructions and Tests
- The project uses the CMake build system. The build system has been configured in the CMakeLists.txt file.
- The configuration declares a dependency on GoogleTest which downloads GoogleTest from GitHub and we can use the GoogleTest code within out project.
- Currently the code only runs via unit tests. You can use following commands to build and run the binary.
```bash
<project_root>$ cmake -S . -B build -Wno-dev
--
--
<project__root>$ cmake --build build
--
--
<project_root>$ cd build && ctest

```
# Linux Build Instructions
- The project requires a C++ compiler, CMake and a build utility like make or Ninja.
- On most Linux distributions, 'make' is preinstalled.
- Please make sure you have required build tools installed on your Linux machine and use the same build commands.
- You can simply install the 'build-essential' package by typing the following command. This package comes with all essential tools like gcc, g++ and make.
```bash
$ sudo apt install build-essential
```
- You can install cmake on Linux by typing:
```bash
$ sudo apt install cmake
```
- Similarly, for macOS, make sure you have all required tools installed.

## Continuous Integration Workflow
- pawan-sutar-coding-challenge/.github/workflows/cmake-multi-platform.yml
- This workflow automatically builds and tests the project whenever changes are pushed to the 'main' branch.
- The aim is to test performance of the code running on different platforms like Windows, Linux and macOS with different compilers like gcc, clang and cl.

## Other Notes
- I have completed all test cases mentioned in pdf but could not add some other edge cases in time.
- I used MSVC build tools (without Visual Studio IDE) to complete the project.

## Questions

## Q. How might your design differ if the list of specialties was expected to never change? What if it changes frequently?
If the list of specialties was static or never changing:-
- Data structure choice- We can use a data structure that facilitates fast lookup such as hash map. The hash map would have real number IDs as keys and string names as values.
- We can optimize the initialization of hash map by populating it with the fixed set of specialties at the beginning of the program.
- After obtaining the list/vector of real number IDs from the input string IDs, we can directly look up the specialty names from the hash map.

If the list of specialties was dynamic or frequently changing
- Data structure choice- In this case, we might need more flexible data structures like databases such as Postgres or MongoDB.
- If we use structured database, we can store IDs and corresponding specialty names in separate columns.
- If we use unstructured or key-value database, we can store IDs as keys and specialty names as values.
- We can also implement an in-memory cache for frequently accessed pairs.
- These approaches are more suitable for large applications.
