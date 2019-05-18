cmake_minimum_required(VERSION 3.13)
project(apProject3)

set(CMAKE_CXX_STANDARD 14)

include_directories(cmake-build-debug)

add_executable(apProject3
    cmake-build-debug/Directory.cpp
    cmake-build-debug/Directory.h
    cmake-build-debug/File.cpp
    cmake-build-debug/File.h
    cmake-build-debug/HardDisk.cpp
    cmake-build-debug/HardDisk.h
    cmake-build-debug/Node.cpp
    cmake-build-debug/Node.h
        cmake-build-debug/MyOS.cpp
        cmake-build-debug/MyOS.h
    cmake-build-debug/Sector.cpp
    cmake-build-debug/Sector.h
    main.cpp)
