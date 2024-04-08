#include "Game.hpp"
#include <iostream>
#include <fstream>
#include "menu.hpp"
using namespace std;
MysteryShip mysteryship;
Spaceship spaceship;

Game::Game(){
    music = LoadMusicStream("Sounds/music.ogg");
    explosionSound = LoadSound("Sounds/explosion.ogg");
    PlayMusicStream(music);
    InitGame();
}

Game::~Game() {
    Alien::UnloadImages();
    UnloadMusicStream(music);
    UnloadSound(explosionSound);
}

void Game::Update() {
    if (run){
        double currentTime = GetTime();
        if(currentTime - timeLastSpawn > mysteryShipInterval){
            mysteryship.Spawn();
            timeLastSpawn = GetTime();
            mysteryShipInterval = GetRandomValue(10, 20);
        }
        if (aliensLeft == 0)
        {
            NextLevel();
            InitNextLevel();

            cout << minusSpeed << endl;
            cout << plusSpeed << endl;
         
            if (lives < 3)
                lives++;
        }
        for(auto& laser: spaceship.lasers) {
            laser.Update();
        }
        MoveAliens();
        AlienShootLaser();
        for (auto& laser: alienLaser)
        {
            laser.Update();
        }
        mysteryship.Update();
        DeleteInactiveLasers();
        CheckForCollisons();
    } else {
        if(IsKeyDown(KEY_ENTER)){
            Reset();
            InitGame();
        }
    }
}



void Game::Draw() {
    spaceship.Draw();

    for(auto& laser: spaceship.lasers) {
        laser.Draw();
    }
    for(auto& obstacle: Obstacles) {
        obstacle.Draw();
    }
    for(auto& alien: aliens) {
        alien.Draw();
    }
        for (auto& laser: alienLaser)
    {
        laser.Draw();
    }
    mysteryship.Draw();
}

void Game::HandleInput() {
    if(run){ 
        if(IsKeyDown(KEY_A)) {
            spaceship.MoveLeft();
        } else if(IsKeyDown(KEY_D)) {
            spaceship.MoveRight();
        } else if(IsKeyDown(KEY_SPACE)) {
            spaceship.FireLazer();
        }
    }
}

void Game::NextLevel()
{
    spaceship.Reset();
    aliens.clear();
    alienLaser.clear();
    Obstacles.clear();
}

void Game::InitNextLevel()
{
    Obstacles = CreateObstacles();
    aliens = CreateAliens();
    timeLastAlienFired = 0;
    timeLastSpawn = 0.0;
    mysteryShipInterval = GetRandomValue(10,15);
    level ++;
    run = true;
    if (alienLaserShootinterval >= 0)
    {
        alienLaserShootinterval -= 0.02;
        cout << alienLaserShootinterval << endl;
    }
    minusSpeed -= 0.25;
    plusSpeed += 0.25;
    aliensLeft = 55;
}

void Game::DeleteInactiveLasers()
{
    for(auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();){
        if(!it -> active){
            it = spaceship.lasers.erase(it);
        } else {
            ++ it;
        }
    }

     for(auto it = alienLaser.begin(); it != alienLaser.end();){
        if(!it -> active){
            it = alienLaser.erase(it);
        } else {
            ++ it;
        }
    }
}

std::vector<Obstacle> Game::CreateObstacles()
{
    int obstacleWidth = Obstacle::grid[0].size() * -4;
    float gap = (GetScreenWidth() - (2 * obstacleWidth))/5.42;

    for (int i = 0; i < 4; i++)
    {
        float offsetX = (i + 1 ) * gap + 1 * obstacleWidth;
        Obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 200)}));
    }
    return Obstacles;
}

std::vector<Alien> Game::CreateAliens()
{
    std::vector<Alien> aliens;
       for(int row = 0; row < 5; row++){
        for(int column = 0; column < 11; column++){
            int alienType;
            if (row == 0) {
                alienType = 3;
            } else if (row == 1 || row == 2) {
                alienType = 2;
            } else
            {
                alienType = 1;
            }

            float x = 75 + column * 55;
            float y = 110 + row * 55;
            aliens.push_back(Alien(alienType, {x,y}));
        }
    }
    return aliens;
}


void Game::MoveAliens() {
    for (auto& alien: aliens) {
        if(alien.position.x + alien.alienImages[alien.type - 1].width > GetScreenWidth() - 9)
        {
            aliensDirection = minusSpeed;
            MoveDownAliens(4);
        }
        if (alien.position.x < 9)
        {
            aliensDirection = plusSpeed;
            MoveDownAliens(4);
        }
        
       alien.Update(aliensDirection);
    }
    
}

void Game::MoveDownAliens(int distance)
{
    for (auto& alien: aliens)
    {
       alien.position.y += distance;
    }
    
}

void Game::AlienShootLaser()
{
    double currentTime = GetTime();
    if(currentTime - timeLastAlienFired >= alienLaserShootinterval && !aliens.empty()){
        int randomIndex = GetRandomValue(0,aliens.size() - 1);
        Alien& alien = aliens[randomIndex];
        alienLaser.push_back(Laser({alien.position.x + alien.alienImages[alien.type - 1].width/2,
        alien.position.y + alien.alienImages[alien.type -1].height}, 6));
        timeLastAlienFired = GetTime();
    }
}

void Game::CheckForCollisons()
{
        //spaceship Lasers

        for(auto& laser: spaceship.lasers){
            auto it = aliens.begin();
            while(it != aliens.end()){
                if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                    PlaySound(explosionSound);
                    if (it -> type == 1){
                            score += 5;
                    } else if (it -> type == 2){
                            score += 10;
                    } else if (it -> type == 3){
                            score += 15;
                    }
                    aliensLeft --;
                    checkForHighscore();
                    it = aliens.erase(it);
                    laser.active = false;
                }else{
                    ++it;
                }
            
            }
            for (auto& obstacle: Obstacles)
            {
                auto it = obstacle.blocks.begin();
                while(it != obstacle.blocks.end()){
                    if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                        it = obstacle.blocks.erase(it);
                        laser.active = false;
                    } else {
                        ++it;
                    }
                }
            }
            if(CheckCollisionRecs(mysteryship.getRect(), laser.getRect())){
                PlaySound(explosionSound);
                mysteryship.alive = false;
                laser.active = false;
                score += 25;
                checkForHighscore();
            }
            
        }
        // alien laser
        for (auto& laser: alienLaser){
            if(CheckCollisionRecs(laser.getRect(), spaceship.getRect())){
                laser.active = false;
                lives --;
                if(lives == 0){
                    
                    
                    GameOver();
                }
            }
                    for (auto& obstacle: Obstacles)
            {
                auto it = obstacle.blocks.begin();
                while(it != obstacle.blocks.end()){
                    if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                        it = obstacle.blocks.erase(it);
                        laser.active = false;
                    } else {
                        ++it;
                    }
                }
            }
        }
        //alien collison with obstacle
        for (auto& alien: aliens){
            for (auto& obstacle: Obstacles){
                auto it = obstacle.blocks.begin();
                while(it != obstacle.blocks.end()){
                    if(CheckCollisionRecs(it -> getRect(), alien.getRect())){
                        it = obstacle.blocks.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
            if(CheckCollisionRecs(alien.getRect(), spaceship.getRect())){
            
            
            GameOver();
        }
    }
}

void Game::GameOver()
{
    run = false;
    
}

void Game::Reset()
{
    spaceship.Reset();
    aliens.clear();
    alienLaser.clear();
    Obstacles.clear();
}

void Game::InitGame()
{
    Obstacles = CreateObstacles();
    aliens = CreateAliens();
    aliensDirection = 1;
    timeLastAlienFired = 0;
    timeLastSpawn = 0.0;
    alienLaserShootinterval = 0.35;
    mysteryShipInterval = GetRandomValue(10,20);
    lives = 3;
    run = true;
    score = 0;
    aliensLeft = 55;
    level = 1;
    plusSpeed = 1.0;
    minusSpeed = -1.0;
    highscore = loadHighscoreFromFile();
}

void Game::checkForHighscore()
{
    if (score > highscore)
    {
        highscore = score;
        saveHighscoreToFile(highscore);
    }
}

void Game::saveHighscoreToFile(int highscore)
{
    ofstream highscoreFile("Highscore2.txt");
    if (highscoreFile.is_open())
    {
        highscoreFile << highscore;
        highscoreFile.close();
    } else{
        cerr << "Failed to save highscore to file\n";
    }
    
}

int Game::loadHighscoreFromFile()
{
    int loadedHighscore = 0;
    ifstream highscoreFile("Highscore2.txt");
        if (highscoreFile.is_open())
    {
        highscoreFile >> loadedHighscore;
        highscoreFile.close();
    } else{
        cerr << "Failed to load highscore from file\n";
    }
    return loadedHighscore;
}
