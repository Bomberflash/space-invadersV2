#include "selection.hpp"

Arrow::Arrow()
{
    image2 = LoadTexture("Graphics/yellow_arrow.png");
    position2.x = GetScreenWidth()/2 - 325;
    position2.y = GetScreenHeight()/2  + 100;
    position3.x = position2.x;
    position3.y = position2.y + 75;
    position4.x = position2.x;
    position4.y = position3.y + 75;
}


void Arrow::Draw()
{
    DrawTextureV(image2,position2,WHITE);
}

void Arrow::Draw2()
{
    DrawTextureV(image2,position3,WHITE);
}

void Arrow::Draw3()
{
    DrawTextureV(image2,position4,WHITE);
}
