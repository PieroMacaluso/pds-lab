cmake_minimum_required(VERSION 3.13)
project(es2)

set(CMAKE_CXX_STANDARD 17)

add_executable(es2 main.cpp Base.cpp Base.h Directory.cpp Directory.h File.cpp File.h)