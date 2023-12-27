cmake_minimum_required(VERSION 3.10)
project(HestonPricer)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Pricer 
	src/payoffs.cpp
	src/payoffs.hpp
	src/main.cpp
	)
