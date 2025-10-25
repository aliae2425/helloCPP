#include "Board.hpp"
#include <iostream>

Board::Board(int width, int height) : width(width), height(height) {
    grid.resize(height, std::vector<CellType>(width, CellType::EMPTY));
}

// TODO: Implémenter le destructeur
Board::~Board() {
    // Nettoyage si nécessaire
}

void Board::clear() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = CellType::EMPTY;
        }
    }
}

void Board::update(const std::vector<std::pair<int, int>>& snakeBody, 
                   const std::pair<int, int>& foodPosition) {
    clear();
    
    // Placer le serpent
    for (size_t i = 0; i < snakeBody.size(); ++i) {
        int x = snakeBody[i].first;
        int y = snakeBody[i].second;
        
        if (isValidPosition(x, y)) {
            if (i == 0) {
                grid[y][x] = CellType::SNAKE_HEAD;
            } else {
                grid[y][x] = CellType::SNAKE_BODY;
            }
        }
    }
    
    // Placer la nourriture
    if (isValidPosition(foodPosition.first, foodPosition.second)) {
        grid[foodPosition.second][foodPosition.first] = CellType::FOOD;
    }
}

void Board::render() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            switch (grid[y][x]) {
                case CellType::EMPTY:
                    std::cout << " ";
                    break;
                case CellType::SNAKE_HEAD:
                    std::cout << "O";
                    break;
                case CellType::SNAKE_BODY:
                    std::cout << "o";
                    break;
                case CellType::FOOD:
                    std::cout << "*";
                    break;
                case CellType::WALL:
                    std::cout << "#";
                    break;
            }
        }
        std::cout << "\n";
    }
}

void Board::renderWithBorders() const {
    // Bordure supérieure avec caractères UTF-8
    std::cout << "┌";
    for (int x = 0; x < width; ++x) {
        std::cout << "─";
    }
    std::cout << "┐\n";
    
    // Contenu avec bordures latérales
    for (int y = 0; y < height; ++y) {
        std::cout << "│";
        for (int x = 0; x < width; ++x) {
            switch (grid[y][x]) {
                case CellType::EMPTY:
                    std::cout << " ";
                    break;
                case CellType::SNAKE_HEAD:
                    std::cout << "🐍";
                    break;
                case CellType::SNAKE_BODY:
                    std::cout << "█";
                    break;
                case CellType::FOOD:
                    std::cout << "🍎";
                    break;
                case CellType::WALL:
                    std::cout << "█";
                    break;
            }
        }
        std::cout << "│\n";
    }
    
    // Bordure inférieure
    std::cout << "└";
    for (int x = 0; x < width; ++x) {
        std::cout << "─";
    }
    std::cout << "┘";
}

void Board::setCell(int x, int y, CellType type) {
    if (isValidPosition(x, y)) {
        grid[y][x] = type;
    }
}

CellType Board::getCell(int x, int y) const {
    if (isValidPosition(x, y)) {
        return grid[y][x];
    }
    return CellType::WALL;
}

// TODO: Implémenter les getters
int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

bool Board::isValidPosition(int x, int y) const {
    return (x >= 0 && x < width && y >= 0 && y < height);
}