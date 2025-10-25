#include "Game.hpp"
#include "InputHandler.hpp"
#include "Utils.hpp"
#include <iostream>

#include <cstdlib>
#include <ctime>

// TODO: Implémenter le constructeur
Game::Game(int boardWidth, int boardHeight) {
    // Initialiser les membres
    srand(time(0));

    Snake Snake(boardWidth / 2, boardHeight / 2);
    Food food(rand() % boardWidth, rand() % boardHeight);
    Board board(boardWidth, boardHeight);
    gameOver = false;
    score = 0;
    gameSpeed = 10; // Vitesse initiale

}

// TODO: Implémenter le destructeur
Game::~Game() {
    // Nettoyage si nécessaire
}

// TODO: Implémenter la boucle principale du jeu
void Game::run() {
    // Logique principale
}

// TODO: Implémenter la mise à jour du game state
void Game::update() {
    // Mettre à jour snake, food, collisions
}

// TODO: Implémenter le rendu
void Game::render() {
    // Afficher le plateau, score, etc.
}

// TODO: Implémenter la gestion des entrées
void Game::handleInput() {
    // Traiter les touches pressées
}

// TODO: Implémenter la détection de collisions
void Game::checkCollisions() {
    // Vérifier collisions murs/snake/food
}

// TODO: Implémenter la génération de nourriture
void Game::generateFood() {
    // Placer nouvelle nourriture
}

// TODO: Implémenter la boucle de jeu
void Game::gameLoop() {
    // Boucle principale avec timer
}

// TODO: Implémenter l'écran de game over
void Game::showGameOver() {
    // Afficher message de fin
}

// TODO: Implémenter l'affichage du score
void Game::showScore() {
    // Afficher le score actuel
}

// TODO: Implémenter les getters
bool Game::isGameOver() const {
    return gameOver;
}

int Game::getScore() const {
    return score;
}