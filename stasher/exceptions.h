#pragma once

#include <stdexcept>

class StasherError: public std::exception {
public:
    StasherError(const std::string& what):
        std::exception(what) {}
};

class ValueError:
    public StasherError {
public:
    ValueError(const std::string& what):
        StasherError(what) {}
};
