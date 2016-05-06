#pragma once

class Entity {
public:
    Property key() const { return properties_.at(KEY_PROPERTY); }
    Property get(const std::string& property) const { return properties_.at(property); }

private:
    std::map<std::string, Property> properties_;
    DateTime committed;
};
