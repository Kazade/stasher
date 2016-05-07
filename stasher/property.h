#pragma once

#include <cstdint>
#include <memory>
#include <cassert>

#include "key.h"

struct DateTime {
    char iso_string[32]; // In ISO format, in UTC
};

typedef std::shared_ptr<std::string> TextPtr;
typedef std::shared_ptr<std::vector<uint8_t>> BlobPtr;

class Property {
public:
    Property(const Key& key);
    Property(int32_t value);
    Property(int64_t value);
    Property(float value);
    Property(const std::string& utf8_string);
    Property(bool value);
    Property(const DateTime& value);
    Property(TextPtr value);
    Property(BlobPtr value);

    Property(const Property& rhs);
    Property& operator=(const Property& rhs);
    ~Property() {}

    template<typename T>
    T value() const;

private:
    PropertyType type_;
    union {
        Key key_property_;
        int64_t int_value_;
        float float_value_;
        char string_value_[MAX_STRING_BYTES];
        bool bool_value_;
        char datetime_value_[32]; // In ISO format, in UTC
    };

    // These should be part of the above union
    // but they are non-trivial and C++ doesn't allow that
    TextPtr text_value_;
    BlobPtr blob_value_;
};

template<>
int64_t Property::value<int64_t>() const {
    assert(type_ == PROPERTY_TYPE_INT64);
    return int_value_;
}

template<>
std::string Property::value<std::string>() const {
    assert(type_ == PROPERTY_TYPE_UNICODE);
    return string_value_;
}
