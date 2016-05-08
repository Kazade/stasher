#include "key.h"
#include "validators.h"

Key::Key(const std::string& kind, int64_t id, const Namespace& ns):
    kind_(kind),
    type_(KEY_TYPE_INT64),
    namespace_(ns) {

    set_value(id);
}

Key::Key(const std::string& kind, const std::string& name, const Namespace &ns):
    kind_(kind),
    type_(KEY_TYPE_UNICODE),
    namespace_(ns) {

    set_value(name);
}

Key::Key(std::shared_ptr<Key> parent_key, int64_t id):
    kind_(parent_key->kind()),
    type_(KEY_TYPE_INT64),
    namespace_(parent_key->ns()) {

    set_value(id);
}

Key::Key(std::shared_ptr<Key> parent_key, const std::string& name):
    kind_(parent_key->kind()),
    type_(KEY_TYPE_UNICODE),
    namespace_(parent_key->ns()) {

    set_value(name);
}

void Key::set_value(int64_t value) {
    type_ = KEY_TYPE_INT64;
    int_value_ = value;
}

void Key::set_value(const std::string& value) {
    validate_key_name(value);

    type_ = KEY_TYPE_UNICODE;
    string_value_ = value;
}
