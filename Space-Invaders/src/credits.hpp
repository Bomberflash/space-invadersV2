#include "menu.hpp"
#pragma once
#include <raylib.h>

class Credits {
    public:
    Credits();
    void Draw();
    private:
    Button button;
    Vector2 position;
};