#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"
#include "Food.hpp"
#include "Board.hpp"

class Game {
private:
    Snake snake;
    Food food;
    Board board;
    bool gameOver;
    int score;
    int gameSpeed;

public:
    Game(int boardWidth, int boardHeight);
    ~Game();
    
    void run();
    void update();
    void render();
    void handleInput();
    void checkCollisions();
    void generateFood();
    void gameLoop();
    void showGameOver();
    void showScore();
    
    bool isGameOver() const;
    int getScore() const;
};

#endif // GAME_HPP