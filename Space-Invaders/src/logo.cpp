#include "logo.hpp"
#include <raylib.h>

Logo::Logo()
{
    image = LoadTexture("Graphics/space_inv.png");
    position.x = GetScreenWidth()/2 - image.width/2;
    position.y = -100;
    
}

void Logo::Draw()
{
    DrawTextureV(image,position,WHITE);

}