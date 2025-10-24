#include "Food.hpp"
#include "Utils.hpp"
#include <algorithm>

// TODO: Implémenter le constructeur
Food::Food(int boardWidth, int boardHeight) {
    // Initialiser avec les dimensions du plateau
}

// TODO: Implémenter le destructeur
Food::~Food() {
    // Nettoyage si nécessaire
}

// TODO: Implémenter la génération de position aléatoire
void Food::generateNewPosition() {
    // Générer position aléatoire sur le plateau
}

// TODO: Implémenter la génération en évitant le serpent
void Food::generateNewPosition(const std::vector<std::pair<int, int>>& snakeBody) {
    // Générer position qui ne soit pas sur le serpent
}

// TODO: Implémenter les getters/setters
std::pair<int, int> Food::getPosition() const {
    return position;
}

bool Food::isEaten(const std::pair<int, int>& snakeHead) const {
    // Vérifier si la nourriture est mangée
    return false;
}

void Food::setBoardSize(int width, int height) {
    boardWidth = width;
    boardHeight = height;
}