cmake_minimum_required(VERSION 3.10)
project(HestonPricer)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib/argparse)

add_executable(Pricer 
	src/payoffs.cpp
	src/payoffs.hpp
	src/main.cpp
	)
target_link_libraries(Pricer PUBLIC
	argparse)
