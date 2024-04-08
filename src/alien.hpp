#pragma once
#include <raylib.h>
#include "game.hpp"

class Alien {
    public:
        Alien(int type, Vector2 position);
        void Update(int Direction);
        void Draw();
        Rectangle getRect();
        int GetType();
        static void UnloadImages();
        static Texture2D alienImages[3];
        int type;
        Vector2 position;
    private:
};