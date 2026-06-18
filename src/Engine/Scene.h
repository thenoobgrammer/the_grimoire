#pragma once

#include <bitset>

typedef unsigned long long EntityID;
const int MAX_COMPONENTS = 32;
typedef std::bitset<MAX_COMPONENTS> ComponentMask;

struct Scene {
    struct EntityDesc {
        EntityID id;
        ComponentMask mask;
    };
    std::vector<EntityDesc> entities;
};