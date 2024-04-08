#include "playbutton.hpp"
#include <raylib.h>


Button::Button()
{
    font = LoadFontEx("Font/monogram.ttf",64,0,0);
    position.x = GetScreenWidth()/2;
    position.y = GetScreenHeight()/2;
}

void Button::Draw()
{
    
    DrawTextEx(font, "PLAY", {position.x - 50, position.y + 100}, 50, 3, yellow);
    DrawTextEx(font, "CREDITS", {position.x - 80, position.y + 250}, 50, 3, yellow);
    DrawRectangleRoundedLines({position.x - 175,position.y + 100,350,55}, 0.80f, 20, 2, yellow);
    DrawRectangleRoundedLines({position.x - 175,position.y + 175,350,55}, 0.80f, 20, 2, yellow);
    DrawTextEx(font, "MEME", {position.x - 50, position.y + 175}, 50, 3, yellow);
    DrawRectangleRoundedLines({position.x - 175,position.y + 250,350,55}, 0.80f, 20, 2, yellow);
    
}
