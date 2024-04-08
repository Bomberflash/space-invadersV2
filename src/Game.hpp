#pragma once
#include "Spaceship.hpp"
#include "Obstacle.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"
#include "menu.hpp"

class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
        bool run;
        int lives;
        int score;
        int highscore;
        Music music;
        std::vector<Alien> aliens;
        int aliensLeft;
        int level;
        float minusSpeed;
        float plusSpeed;
        Menu menu;
        void Reset();
        void InitGame();
        bool meme;
    private:
        void NextLevel();
        void InitNextLevel();
        void DeleteInactiveLasers();
        std::vector<Obstacle> CreateObstacles();
        std::vector<Alien> CreateAliens();
        void MoveAliens();
        void MoveDownAliens(int distance);
        void AlienShootLaser();
        void CheckForCollisons();
        void GameOver();
        
        void checkForHighscore();
        void saveHighscoreToFile(int highscore);
        int loadHighscoreFromFile();
        Spaceship spaceship;
        std::vector<Obstacle> Obstacles;
        float aliensDirection;
        std::vector<Laser> alienLaser;
        float alienLaserShootinterval = 0.35;
        float timeLastAlienFired;
        MysteryShip mysteryship;
        float mysteryShipInterval;
        float timeLastSpawn;
        Sound explosionSound;
        
};
