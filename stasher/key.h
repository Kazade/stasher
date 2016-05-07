#pragma once

#include <string>
#include <cstdint>
#include <memory>

#include "constants.h"

enum KeyType {
    KEY_TYPE_INT64,
    KEY_TYPE_UNICODE
};

class Key {
public:
    Key(const std::string& kind, const std::string& ns="");
    Key(const std::string& kind, int64_t id, const std::string& ns="");
    Key(const std::string& kind, const std::string& name, const std::string& ns="");
    Key(std::shared_ptr<Key> parent_key, int64_t id);
    Key(std::shared_ptr<Key> parent_key, const std::string& name);

    bool is_root() const { return !parent_key_; }
    Key* entity_group_key() const { return root_key_; }

    std::string kind() const { return kind_; }
    std::string ns() const { return namespace_; }

    bool is_id() const { return type_ == KEY_TYPE_INT64; }
    bool is_name() const { return type_ == KEY_TYPE_UNICODE; }

    bool is_complete() const {
        return (type_ == KEY_TYPE_INT64 && int_value_ > 0) ||
                (type_ == KEY_TYPE_UNICODE && !string_value_.empty());
    }
private:
    void set_value(int64_t value);
    void set_value(const std::string& value);

    std::shared_ptr<Key> parent_key_;
    Key* root_key_ = nullptr;

    std::string kind_;
    std::string namespace_;

    KeyType type_;
    union {
        int64_t int_value_;
        std::string string_value_;
    };
};
