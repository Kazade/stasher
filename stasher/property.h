#pragma once

#include <cstdint>
#include <memory>

#include "key.h"

struct DateTime {
    char iso_string[32]; // In ISO format, in UTC
};

struct Text {
    std::shared_ptr<std::string> data;
};

struct Blob {
    std::shared_ptr<std::string> data;
};

class Property {
public:
    Property(const Key& key);
    Property(int64_t value);
    Property(float value);
    Property(const std::string& utf8_string);
    Property(bool value);
    Property(const DateTime& value);
    Property(const Text& value);
    Property(const Blob& value);

private:
    PropertyType type_;
    union {
        Key key_property_;
        int64_t int_value_;
        float float_value_;
        char string_value_[MAX_STRING_BYTES];
        bool bool_value_;
        Text text_value_;
        Blob blob_value_;
        char datetime_value_[32]; // In ISO format, in UTC
    };
};
