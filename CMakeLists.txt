cmake_minimum_required(VERSION 3.6)
project(Embedded_Systems___Kommandozeilenparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -fno-exceptions -Wno-format -fno-rtti -std=c++1y")

set(SOURCE_FILES main.cpp OptParser.cpp OptParser.h)
add_executable(Embedded_Systems___Kommandozeilenparser ${SOURCE_FILES})