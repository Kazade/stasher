#include "entity.h"

std::ostream& operator<<(std::ostream& os, const Entity& entity) {
    assert(0 && "Not Implemented");
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
