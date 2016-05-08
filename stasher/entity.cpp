#include "entity.h"

Entity::Entity(const std::string& kind, int64_t id) {
    properties_[KEY_PROPERTY] = Key(kind, id);
}

Entity::Entity(const std::string& kind, const std::string& name) {
    properties_[KEY_PROPERTY] = Key(kind, name);
}

void Entity::set(const std::string& property, Property value) {
    properties_[property] = value;
}
