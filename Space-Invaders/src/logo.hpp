#pragma once
#include <raylib.h>

class Logo {
    public:
    Logo();
    void Draw();
    Texture2D image;
    private:
    Vector2 position;
};