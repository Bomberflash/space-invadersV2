#include <raylib.h>
#include "game.hpp"
#include <string>
#include <iostream>
#include "menu.hpp"

using namespace std;
#include "credits.hpp"



string FormatWithLeadingZeros(int number, int width){
        string numberText = to_string(number);
        int LeadingZeros = 5 - numberText.length();
        return numberText = string(LeadingZeros,'0') + numberText;
}

    int main()
{   
    
    Color yellow = {243,216,63,255};
    int offset = 50;
    int windowWidth = 750;
    int windowHeight = 700;
    
    Color backgroundcolor = {0,0,0,255};
    bool idkk = true;
    InitWindow(windowWidth + offset,windowHeight + 2 * offset, "c++ space invadorrrsss");
    InitAudioDevice();
    Font font = LoadFontEx("Font/monogram.ttf",64,0,0);
    Texture2D Spaceshipimage = LoadTexture("Graphics/spaceship.png");
    SetTargetFPS(60);
    Credits credits;
    Game game;
    Menu menu;
    
    //Alien alien = Alien(1,{100,100});

    while(WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        
        BeginDrawing();
        ClearBackground(backgroundcolor);
        if (menu.INTERGAMEBOOLRIGHTHERE == false)
        {if (idkk)
            {
                menu.Draw();
            }
        }


        if (menu.down2 == true && IsKeyPressed(KEY_ENTER) && menu.play == false)
        {
            idkk = false;
        }
        if (idkk == false)
        {
            credits.Draw();
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            idkk = true;
        }
        if ((menu.down == true && IsKeyPressed(KEY_ENTER) )|| menu.INTERGAMEBOOLRIGHTHERE)
        {
            if(game.run){

            if (game.run && menu.INTERGAMEBOOLRIGHTHERE == false)
            {
                game.Reset();
                game.InitGame();
            }
                menu.INTERGAMEBOOLRIGHTHERE = true;
                game.meme = true;

                    DrawTextEx(font, "LEVEL", {550, 740}, 34, 2, yellow);
                    string levelText = FormatWithLeadingZeros(game.level, 0);
                    DrawTextEx(font, levelText.c_str(), {650,740}, 34,2,yellow);

                } else {
                    DrawTextEx(font, "GAME OVER", {570, 740}, 34,2, yellow);
                    if(IsKeyDown(KEY_BACKSPACE)){
                        menu.INTERGAMEBOOLRIGHTHERE = false;
                        game.run = true;
                
                }
            
                
                }
                float x = 50.0;
                for (int i = 0; i < game.lives; i++)
                {
                    DrawTextureV(Spaceshipimage,{x, 745}, WHITE);
                    x += 50;
                }
            
                DrawTextEx(font, "SCORE", {50,15}, 34, 2, yellow);
                string scoreText = FormatWithLeadingZeros(game.score, 0);
                DrawTextEx(font, scoreText.c_str(), {50,40}, 34,2,yellow);

                DrawTextEx(font, "HIGH-SCORE", {570,15}, 34, 2, yellow);
                string highscoreText = FormatWithLeadingZeros(game.highscore, 0);
                DrawTextEx(font, highscoreText.c_str(), {655,40}, 34,2,yellow);
        
                game.Draw();
                //alien.Draw();
        }
            
        
        

        if ((menu.play && IsKeyPressed(KEY_ENTER)) || menu.INTERGAMEBOOLRIGHTHERE)
        {
            if (game.run && menu.INTERGAMEBOOLRIGHTHERE == false)
            {
                game.Reset();
                game.InitGame();
            }
            

        menu.INTERGAMEBOOLRIGHTHERE = true;

        game.HandleInput();
        game.Update();
        DrawRectangleRoundedLines({ 10, 10, 780, 780}, 0.18f, 20, 2, yellow);
        DrawLineEx({25, 730},{775, 730},3,yellow);

        if(game.run){

            DrawTextEx(font, "LEVEL", {550, 740}, 34, 2, yellow);
            string levelText = FormatWithLeadingZeros(game.level, 0);
            DrawTextEx(font, levelText.c_str(), {650,740}, 34,2,yellow);

        } else {
            DrawTextEx(font, "GAME OVER", {570, 740}, 34,2, yellow);
                    if(IsKeyDown(KEY_BACKSPACE)){
            menu.INTERGAMEBOOLRIGHTHERE = false;
            game.run = true;
            
        }
           
            
        }
        float x = 50.0;
        for (int i = 0; i < game.lives; i++)
        {
            DrawTextureV(Spaceshipimage,{x, 745}, WHITE);
            x += 50;
        }
        
        DrawTextEx(font, "SCORE", {50,15}, 34, 2, yellow);
        string scoreText = FormatWithLeadingZeros(game.score, 0);
        DrawTextEx(font, scoreText.c_str(), {50,40}, 34,2,yellow);

        DrawTextEx(font, "HIGH-SCORE", {570,15}, 34, 2, yellow);
        string highscoreText = FormatWithLeadingZeros(game.highscore, 0);
        DrawTextEx(font, highscoreText.c_str(), {655,40}, 34,2,yellow);
    
        game.Draw();
        //alien.Draw();

        }
        
        EndDrawing();
    }
    
    CloseWindow();
    CloseAudioDevice();
    
}












