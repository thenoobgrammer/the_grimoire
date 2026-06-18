#pragma once

#include <string>
#include <list>

#include "Component.h"
#include "EntityRegistry.h"

class Entity {
    unsigned int id;
    std::string name;
    std::list<std::string> tags;
    std::list<Component> components;
public:
    unsigned static int next_id;

    Entity(const std::string &name, const std::list<std::string> &tags): name(name), tags(tags) {
        id = next_id++;
    }
    unsigned int getId() const {
        return id;
    }
    std::string getName() {
        return name;
    }
    std::list<std::string> getTags() {
        return tags;
    }
};
