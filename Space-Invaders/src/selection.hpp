#pragma once
#include <raylib.h>

class Arrow {
    public:
    Arrow();
    void Draw();
    void Draw2();
    void Draw3();
    Texture2D image2;
    private:
    Vector2 position2;
    Vector2 position3;
    Vector2 position4;
    Font font;
};