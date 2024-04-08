#include <raylib.h>
#include "playbutton.hpp"
#include "logo.hpp"
#include "selection.hpp"
#pragma once

class Menu {
    public:
    Menu();
    void Draw();
    bool up = true;
    bool down = false;
    bool down2 = false;
    bool play = true;
    bool INTERGAMEBOOLRIGHTHERE = false;
    
    private:
    Logo logo;
    Arrow arrow;
    Button button;
};