#pragma once

#include <string>
#include <cstdint>
#include <memory>

#include "constants.h"

enum KeyType {
    KEY_TYPE_INT64,
    KEY_TYPE_UNICODE
};

struct Namespace {
public:
    Namespace() {}

    Namespace(const std::string& ns):
        namespace_(ns) {}

    Namespace& operator=(const char* ns) {
        *this = std::string(ns);
        return *this;
    }

    Namespace& operator=(const std::string& ns) {
        namespace_ = ns;
        return *this;
    }

private:
    std::string namespace_;
};

class Key {
public:
    Key() {}
    Key(const Key& key) = default;

    Key(const std::string& kind, const Namespace& ns=Namespace(""));
    Key(const std::string& kind, int64_t id, const Namespace& ns=Namespace(""));
    Key(const std::string& kind, const std::string& name, const Namespace& ns=Namespace(""));

    Key(std::shared_ptr<Key> parent_key, int64_t id);
    Key(std::shared_ptr<Key> parent_key, const std::string& name);

    bool is_root() const { return !parent_key_; }
    Key* entity_group_key() const { return root_key_; }

    std::string kind() const { return kind_; }
    Namespace ns() const { return namespace_; }

    bool is_id() const { return type_ == KEY_TYPE_INT64; }
    bool is_name() const { return type_ == KEY_TYPE_UNICODE; }

    bool is_complete() const {
        return !kind_.empty() &&
                ((type_ == KEY_TYPE_INT64 && int_value_ > 0) ||
                (type_ == KEY_TYPE_UNICODE && !string_value_.empty()));
    }
private:
    void set_value(int64_t value);
    void set_value(const std::string& value);

    std::shared_ptr<Key> parent_key_;
    Key* root_key_ = nullptr;

    std::string kind_;
    Namespace namespace_;

    KeyType type_ = KEY_TYPE_INT64;
    int64_t int_value_ = 0;
    std::string string_value_;

    friend std::ostream& operator<<(std::ostream& os, const Key& property);
};

std::ostream& operator<<(std::ostream& os, const Key& property);
