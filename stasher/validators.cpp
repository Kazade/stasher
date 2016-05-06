
#include "validators.h"

void validate_string(const std::string& value) {
    if(value.length() > MAX_STRING_BYTES) {
        throw ValueError("Value too long for indexed property");
    }
}

void validate_key_name(const std::string &name) {
    validate_string(name);

    if(name.find("__") == 0) {
        throw ValueError("Key names cannot start with a double underscore ('__')");
    }
}

void validate_int64(const int64_t value) {

}

