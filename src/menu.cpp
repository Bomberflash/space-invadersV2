#include "menu.hpp"
#include <iostream>

Menu::Menu()
{

}

void Menu::Draw()
{
    logo.Draw();
    button.Draw();
    if (up ||( IsKeyPressed(KEY_W) && down == true)){ if (IsKeyPressed(KEY_S))
    {
        up = false;
        down = true;
    } else {
        play = true;
        down2 = false;
        up = true;
        arrow.Draw();
    }
    
    } else if (down) {if (down2 ||( IsKeyPressed(KEY_S) && down2 == false))
    {
            play = false;
            down2 = true;
    } else if (IsKeyPressed(KEY_W) && down2 == true)
        {  
            down = true;
            up = false;
        } else if (IsKeyPressed(KEY_W) && down2 == false)
        {
            down = false;
            up = true;
        } else {
        play = false;
        down2 = false;
        down = true;
        arrow.Draw2();
    }
    }

    
    
    
}
