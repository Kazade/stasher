CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(stasher)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

SET(
    SOURCES
    stasher/key.cpp
    stasher/property.cpp
    stasher/validators.cpp
    stasher/entity.cpp
)

ADD_LIBRARY(
    stasher
    ${SOURCES}
)

ADD_SUBDIRECTORY(tests)
