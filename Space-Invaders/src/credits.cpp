#include "credits.hpp"

Credits::Credits()
{
    position.x = GetScreenWidth()/10;
    position.y = 100;
    
}

void Credits::Draw()
{
    DrawTextEx(button.font, "MAIN MENU BY - LOUIS", {position.x, position.y}, 34, 2, button.yellow);
    DrawTextEx(button.font, "GAME MADE BY - LOUIS", {position.x, position.y+ 30}, 34, 2, button.yellow);
    DrawTextEx(button.font, "SCRIPTED BY - LOUIS", {position.x, position.y+ 60}, 34, 2, button.yellow);
    DrawTextEx(button.font, "HONORABLE MENTION - LOUIS", {position.x, position.y+ 90}, 34, 2, button.yellow);
    DrawTextEx(button.font, "THE GUY WHO MADE IT IS - LOUIS", {position.x, position.y+ 120}, 34, 2, button.yellow);
    DrawTextEx(button.font, "THE COOL GUY IS - LOUIS", {position.x, position.y+ 150}, 34, 2, button.yellow);
    DrawTextEx(button.font, "THANKS TO - LUIS FOR HELPING WITH BUGS", {position.x, position.y+ 180}, 34, 2, button.yellow);
    DrawTextEx(button.font, "SFX/MUSIC BY - GOOGLE", {position.x, position.y+ 210}, 34, 2, button.yellow);
}
