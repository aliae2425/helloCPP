#include "Game.hpp"
#include "InputHandler.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#endif

Game::Game(int boardWidth, int boardHeight) 
    : snake(boardWidth / 2, boardHeight / 2),
      food(boardWidth, boardHeight),
      board(boardWidth, boardHeight),
      gameOver(false),
      score(0),
      gameSpeed(150) {
    srand(time(0));
    generateFood();
}

// TODO: Implémenter le destructeur
Game::~Game() {
    // Nettoyage si nécessaire
}

void Game::run() {
    Console::clear();
    Console::hideCursor();
    
    while (!gameOver) {
        handleInput();
        update();
        render();
        
        // Attendre selon la vitesse du jeu
        std::this_thread::sleep_for(std::chrono::milliseconds(gameSpeed));
    }
    
    showGameOver();
    Console::showCursor();
}

void Game::update() {
    snake.move();
    checkCollisions();
    board.update(snake.getBody(), food.getPosition());
}

void Game::render() {
    Console::gotoxy(0, 0);
    board.renderWithBorders();
    showScore();
}

void Game::handleInput() {
    #ifdef _WIN32
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'z': case 'Z': case 72: // Z ou flèche haut
                snake.changeDirection(Direction::UP);
                break;
            case 's': case 'S': case 80: // S ou flèche bas
                snake.changeDirection(Direction::DOWN);
                break;
            case 'q': case 'Q': case 75: // Q ou flèche gauche
                snake.changeDirection(Direction::LEFT);
                break;
            case 'd': case 'D': case 77: // D ou flèche droite
                snake.changeDirection(Direction::RIGHT);
                break;
            case 27: // ESC
                gameOver = true;
                break;
        }
    }
    #endif
}

void Game::checkCollisions() {
    // Vérifier collision avec la nourriture
    if (food.isEaten(snake.getHead())) {
        snake.grow();
        score += 10;
        generateFood();
        // Augmenter légèrement la vitesse
        if (gameSpeed > 50) {
            gameSpeed -= 2;
        }
    }
    
    // Vérifier collision avec les murs
    if (snake.checkWallCollision(board.getWidth(), board.getHeight())) {
        gameOver = true;
    }
    
    // Vérifier auto-collision
    if (snake.checkSelfCollision()) {
        gameOver = true;
    }
}

void Game::generateFood() {
    food.generateNewPosition(snake.getBody());
}

void Game::gameLoop() {
    run();
}

void Game::showGameOver() {
    Console::clear();
    std::cout << "\n\n";
    std::cout << "  ╔═══════════════════════════════╗\n";
    std::cout << "  ║        💀 GAME OVER! 💀        ║\n";
    std::cout << "  ╚═══════════════════════════════╝\n\n";
    std::cout << "  🏆 Score final: " << score << "\n";
    std::cout << "  🐍 Taille du serpent: " << snake.getSize() << "\n";
    std::cout << "  🍎 Pommes mangées: " << score / 10 << "\n\n";
    std::cout << "  ⌨️  Appuyez sur une touche pour quitter...\n";
    
    #ifdef _WIN32
    _getch();
    #else
    std::cin.get();
    #endif
}

void Game::showScore() {
    std::cout << "\n 🏆 Score: " << score << " | 📏 Taille: " << snake.getSize() << " | ⚡ Vitesse: " << (200 - gameSpeed);
    std::cout << "\n 🎮 Contrôles: Z/Q/S/D ou flèches - ESC pour quitter\n";
}

// TODO: Implémenter les getters
bool Game::isGameOver() const {
    return gameOver;
}

int Game::getScore() const {
    return score;
}