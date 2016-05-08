#include "property.h"
#include "validators.h"

Property::Property(const Key& key):
    type_(PROPERTY_TYPE_KEY),
    key_value_(key) {

}

Property::Property(int64_t value):
    type_(PROPERTY_TYPE_INT64),
    int_value_(value) {

}

Property::Property(float value):
    type_(PROPERTY_TYPE_FLOAT),
    float_value_(value) {

}

Property::Property(const std::string& utf8_string):
    type_(PROPERTY_TYPE_UNICODE) {

    validate_string(utf8_string);
    std::copy(utf8_string.begin(), utf8_string.end(), string_value_);
}

Property::Property(bool value):
    type_(PROPERTY_TYPE_BOOLEAN),
    bool_value_(value) {

}

Property::Property(const DateTime& value):
    type_(PROPERTY_TYPE_DATETIME),
    datetime_value_(value) {

}

Property::Property(TextPtr value):
    type_(PROPERTY_TYPE_TEXT),
    text_value_(value) {

}

Property::Property(BlobPtr value):
    type_(PROPRETY_TYPE_BLOB),
    blob_value_(value) {

}

bool Property::operator==(const Property& rhs) const {

}

bool Property::operator!=(const Property& rhs) const {

}
