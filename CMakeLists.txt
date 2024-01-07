cmake_minimum_required(VERSION 3.16.3)
project(conductor)

include_directories(include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES "src/*.cpp")
add_executable(conductor ${SOURCE_FILES})
