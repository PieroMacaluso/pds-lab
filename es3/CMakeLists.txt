cmake_minimum_required(VERSION 3.13)
project(es3)

set(CMAKE_CXX_STANDARD 17)

add_executable(es3 main.cpp NetworkServer.cpp NetworkServer.h Message.cpp Message.h SharedEditor.cpp SharedEditor.h Symbol.cpp Symbol.h)