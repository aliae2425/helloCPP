#include "Food.hpp"
#include "Utils.hpp"
#include <algorithm>

Food::Food(int boardWidth, int boardHeight) 
    : boardWidth(boardWidth), boardHeight(boardHeight) {
    generateNewPosition();
}

// TODO: Implémenter le destructeur
Food::~Food() {
    // Nettoyage si nécessaire
}

void Food::generateNewPosition() {
    position.first = rand() % boardWidth;
    position.second = rand() % boardHeight;
}

void Food::generateNewPosition(const std::vector<std::pair<int, int>>& snakeBody) {
    bool validPosition = false;
    
    while (!validPosition) {
        position.first = rand() % boardWidth;
        position.second = rand() % boardHeight;
        
        validPosition = true;
        // Vérifier que la position n'est pas sur le serpent
        for (const auto& segment : snakeBody) {
            if (segment.first == position.first && segment.second == position.second) {
                validPosition = false;
                break;
            }
        }
    }
}

// TODO: Implémenter les getters/setters
std::pair<int, int> Food::getPosition() const {
    return position;
}

bool Food::isEaten(const std::pair<int, int>& snakeHead) const {
    return (snakeHead.first == position.first && snakeHead.second == position.second);
}

void Food::setBoardSize(int width, int height) {
    boardWidth = width;
    boardHeight = height;
}