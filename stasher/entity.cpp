#include <iostream>
#include "entity.h"

std::ostream& operator<<(std::ostream& os, const Entity& entity) {
    os << std::string("{");
    os << "__key__ : " << entity.key() << ", ";
    entity.each([&](uint32_t i, const std::string& property_name, const Property& p) {
        os << property_name;
        os << std::string(" : ");
        os << p;
        if(i < entity.property_count() - 1) {
            os << ", ";
        }
    });
    os << std::string("}");
    return os;
}


Entity::Entity(const std::string& kind, int64_t id) {
    key_ = Key(kind, id);
}

Entity::Entity(const std::string& kind, const std::string& name) {
    key_ = Key(kind, name);
}

void Entity::set(const std::string& property, Property value) {
    if(properties_.count(property)) {
        properties_.at(property) = value;
    } else {
        properties_.insert(std::make_pair(property, value));
    }
}

void Entity::each(std::function<void (uint32_t i, const std::string&, const Property&)> func) const {
    uint32_t i = 0;
    for(auto& p: properties_) {
        func(i++, p.first, p.second);
    }
}
