#pragma once

class Component {
    unsigned static next_id;
    unsigned int id;

    Component() {
        id = next_id++;
    };

    ~Component() = default;

    get() {
        return this;
    }

    getId() {
        return id;
    }
};