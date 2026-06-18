#pragma once

class System {
public:

    unsigned static int next_id;
    unsigned int id;

    System() {}

    virtual void update() = 0;
    virtual ~System() = default;
};