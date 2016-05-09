#include "property.h"
#include "validators.h"

std::ostream& operator<<(std::ostream& os, const Property& property) {
    switch(property.type_) {
        case PROPERTY_TYPE_BOOLEAN:
            os << ((property.bool_value_) ? std::string("true") : std::string("false"));
            break;
        case PROPERTY_TYPE_INT64:
            os << std::to_string(property.int_value_);
            break;
        case PROPERTY_TYPE_UNICODE:
            os << property.string_value_;
            break;
        default:
            assert(0 && "Not Implemented");
    }

    return os;
}

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
    string_value_ = utf8_string;
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
    if(type_ != rhs.type_) {
        return false;
    }

    switch(type_) {
        case PROPERTY_TYPE_INT64:
            return int_value_ == rhs.int_value_;
        break;
        case PROPERTY_TYPE_UNICODE:
            return string_value_ == rhs.string_value_;
        break;
        case PROPERTY_TYPE_BOOLEAN:
            return bool_value_ == rhs.bool_value_;
        break;
        default:
            assert(0 && "Not Implemented");
    }
}

bool Property::operator!=(const Property& rhs) const {
    return !(*this == rhs);
}
