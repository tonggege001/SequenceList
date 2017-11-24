cmake_minimum_required(VERSION 3.8)
project(DataStructure)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp  SequenceList.h SequenceList.cpp main_.cpp)
add_executable(DataStructure ${SOURCE_FILES} main_.cpp)