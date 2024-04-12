cmake_minimum_required(VERSION 3.10)
project(RaceSimulator)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(race_simulator
    src/main.cpp
    src/Car.cpp
    src/Driver.cpp
    src/Track.cpp
)
target_include_directories(race_simulator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})