CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(stasher)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

SET(
    SOURCES
    stasher/key.cpp
)

ADD_LIBRARY(
    stasher
    ${SOURCES}
)


