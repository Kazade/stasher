#pragma once

#include <stdexcept>

class StasherError: public std::runtime_error {
public:
    StasherError(const std::string& what):
        std::runtime_error(what) {}
};

class InvalidValueError:
    public StasherError {
public:
    InvalidValueError(const std::string& what):
        StasherError(what) {}
};

class EntityNotFoundError:
    public StasherError {
public:
    EntityNotFoundError(const std::string& what):
        StasherError(what) {}
};
