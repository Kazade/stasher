#pragma once

#include <map>

#include "property.h"

class Entity {
public:
    Entity(const std::string& kind, int64_t id);
    Entity(const std::string& kind, const std::string& name);

    Property key() const { return key_; }
    Property get(const std::string& property) const { return properties_.at(property); }

    void set(const std::string& property, Property value);

    bool operator==(const Entity& rhs) const {
        if(this == &rhs) {
            return true;
        }

        for(auto p: properties_) {
            // If the rhs is missing a property, return false
            if(!rhs.properties_.count(p.first)) {
                return false;
            }

            // If the rhs property != then return false
            if(p.second != rhs.properties_.at(p.first)) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Entity& rhs) const {
        return !(*this == rhs);
    }

private:
    Key key_;
    std::map<std::string, Property> properties_;

    friend std::ostream& operator<<(std::ostream& os, const Entity& entity);
};

std::ostream& operator<<(std::ostream& os, const Entity& entity);
