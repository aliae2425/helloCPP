#include "Snake.hpp"

// TODO: Implémenter le constructeur
Snake::Snake(int startX, int startY) {
    // Initialiser le serpent à la position de départ
    body.push_back({startX, startY});
    currentDirection = Direction::RIGHT;
}

// TODO: Implémenter le destructeur
Snake::~Snake() {
    // Nettoyage si nécessaire
}

// TODO: Implémenter le mouvement
void Snake::move() {
    // Déplacer le serpent selon la direction


}

// TODO: Implémenter le changement de direction
void Snake::changeDirection(Direction newDirection) {
    // Changer la direction si valide (pas opposée)
}

// TODO: Implémenter la croissance
void Snake::grow() {
    // Augmenter la taille du serpent
    body.push_back(body.back());
}

// TODO: Implémenter le reset
void Snake::reset(int startX, int startY) {
    // Remettre le serpent à l'état initial
    body.clear();
    body.push_back({startX, startY});
    
}

// TODO: Implémenter la détection d'auto-collision
bool Snake::checkSelfCollision() const {
    // Vérifier si la tête touche le corps
    return false;
}

// TODO: Implémenter la détection de collision avec les murs
bool Snake::checkWallCollision(int boardWidth, int boardHeight) const {
    // Vérifier si le serpent sort du plateau
    return false;
}

// TODO: Implémenter les getters
std::pair<int, int> Snake::getHead() const {
    // Retourner la position de la tête
    return {0, 0};
}

const std::vector<std::pair<int, int>>& Snake::getBody() const {
    return body;
}

int Snake::getSize() const {
    return body.size();
}

Direction Snake::getCurrentDirection() const {
    return currentDirection;
}