#pragma once
#include <raylib.h>

class Button {
    public:
        Button();
        void Draw();
        Font font;
        Color yellow{243,216,63,255};
    private:
    Vector2 position;
    
};