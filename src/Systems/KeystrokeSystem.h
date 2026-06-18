#pragma once

#include "System.h"

class KeystrokeSystem: public System {
public:
    KeystrokeSystem() {}

    void update() override {

        Logger::Log("Calling the keystroke system");
    }
};