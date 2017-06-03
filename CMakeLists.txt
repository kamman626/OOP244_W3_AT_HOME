cmake_minimum_required(VERSION 3.6)
project(OOP244_W3_AT_HOME)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        CRA_Account.cpp
        CRA_Account.h
        w3_at_home.cpp)

add_executable(OOP244_W3_AT_HOME ${SOURCE_FILES})