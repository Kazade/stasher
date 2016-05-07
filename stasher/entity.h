#pragma once

#include "property.h"

class Entity {
public:
    Entity(const std::string& kind, int64_t id);
    Entity(const std::string& kind, const std::string& name);

    Property key() const { return properties_.at(KEY_PROPERTY); }
    Property get(const std::string& property) const { return properties_.at(property); }

    void set(const std::string& property, Property value);
private:
    std::map<std::string, Property> properties_;
    DateTime committed;
};
