#include "Spaceship.hpp"

Spaceship::Spaceship()
{
    Game game;
    if (game.meme){
    image = LoadTexture("Graphics/obama.png");
    } else {
    image = LoadTexture("Graphics/spaceship.png");
    }
    position.x = (GetScreenWidth() - image.width)/2;
    position.y = GetScreenHeight() - image.height - 100;
    lastFireTime = 0.0;
    laserSound = LoadSound("Sounds/laser.ogg");
}

Spaceship::~Spaceship() {
    UnloadTexture(image);
    UnloadSound(laserSound);
}

void Spaceship::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft() {
    position.x -= 7;
    if (position.x < 9) {
        position.x = 9;
    }
}

void Spaceship::MoveRight() {
    position.x += 7;
        if (position.x > GetScreenWidth() - image.width - 9) {
        position.x = GetScreenWidth() - image.width - 9;
    }
}

void Spaceship::FireLazer()
{
    if(GetTime() - lastFireTime >= 0){
    lasers.push_back(Laser({position.x + image.width/2 - 2,position.y},-20));
    lastFireTime = GetTime();
    PlaySound(laserSound);
    }
}

Rectangle Spaceship::getRect()
{
    return {position.x,position.y,float(image.width), float(image.height)};
}

void Spaceship::Reset()
{
    position.x = (GetScreenWidth() - image.width)/ 2.0f;
    position.y = GetScreenHeight() - image.height - 100;
    lasers.clear();
}
