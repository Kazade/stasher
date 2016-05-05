#pragma once

#include <string>
#include <memory>
#include <map>

const uint32_t MAX_STRING_BYTES = 1500;
const std::string KEY_PROPERTY = "__key__";

enum PropertyType {
    PROPERTY_TYPE_NONE,
    PROPERTY_TYPE_INT64,
    PROPERTY_TYPE_FLOAT,
    PROPERTY_TYPE_UNICODE,
    PROPERTY_TYPE_BOOLEAN,
    PROPERTY_TYPE_TEXT,
    PROPRETY_TYPE_BLOB,
    PROPERTY_TYPE_DATETIME
};

struct Key {
    Property id_or_name;
};

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
        int64_t int_value_;
        float float_value_;
        char string_value_[MAX_STRING_BYTES];
        bool bool_value_;
        Text text_value_;
        Blob blob_value_;
        char datetime_value_[32]; // In ISO format, in UTC
    };
};

class Entity {
public:
    Property key() const { return properties_.at(KEY_PROPERTY); }
    Property get(const std::string& property) const { return properties_.at(property); }

private:
    std::map<std::string, Property> properties_;
    DateTime committed;
};
