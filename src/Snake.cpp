#include "Snake.hpp"

Snake::Snake(int startX, int startY) {
    // Créer un serpent initial de 3 segments
    body.push_back({startX, startY});
    body.push_back({startX - 1, startY});
    body.push_back({startX - 2, startY});
    
    currentDirection = Direction::RIGHT;
    nextDirection = Direction::RIGHT;
    hasEaten = false;
}

// TODO: Implémenter le destructeur
Snake::~Snake() {
    // Nettoyage si nécessaire
}

void Snake::move() {
    // Mettre à jour la direction actuelle
    currentDirection = nextDirection;
    
    // Calculer la nouvelle position de la tête
    std::pair<int, int> newHead = body.front();
    switch (currentDirection) {
        case Direction::UP:
            newHead.second -= 1;
            break;
        case Direction::DOWN:
            newHead.second += 1;
            break;
        case Direction::LEFT:
            newHead.first -= 1;
            break;
        case Direction::RIGHT:
            newHead.first += 1;
            break;
    }
    
    // Ajouter la nouvelle tête
    body.insert(body.begin(), newHead);
    
    // Supprimer la queue sauf si le serpent a mangé
    if (!hasEaten) {
        body.pop_back();
    } else {
        hasEaten = false;
    }
}void Snake::changeDirection(Direction newDirection) {
    // Empêcher le serpent de faire demi-tour
    if ((currentDirection == Direction::UP && newDirection == Direction::DOWN) ||
        (currentDirection == Direction::DOWN && newDirection == Direction::UP) ||
        (currentDirection == Direction::LEFT && newDirection == Direction::RIGHT) ||
        (currentDirection == Direction::RIGHT && newDirection == Direction::LEFT)) {
        return;
    }
    
    nextDirection = newDirection;
}

void Snake::grow() {
    hasEaten = true;
}

void Snake::reset(int startX, int startY) {
    body.clear();
    body.push_back({startX, startY});
    body.push_back({startX - 1, startY});
    body.push_back({startX - 2, startY});
    
    currentDirection = Direction::RIGHT;
    nextDirection = Direction::RIGHT;
    hasEaten = false;
}

bool Snake::checkSelfCollision() const {
    if (body.size() < 2) return false;
    
    std::pair<int, int> head = body.front();
    
    // Vérifier si la tête est sur le corps (ignorer le premier segment qui est la tête)
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i].first == head.first && body[i].second == head.second) {
            return true;
        }
    }
    
    return false;
}

bool Snake::checkWallCollision(int boardWidth, int boardHeight) const {
    std::pair<int, int> head = body.front();
    
    return (head.first < 0 || head.first >= boardWidth || 
            head.second < 0 || head.second >= boardHeight);
}

std::pair<int, int> Snake::getHead() const {
    return body.empty() ? std::make_pair(0, 0) : body.front();
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