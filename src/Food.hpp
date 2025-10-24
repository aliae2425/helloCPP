#ifndef FOOD_HPP
#define FOOD_HPP

#include <utility>
#include <vector>

class Food {
private:
    std::pair<int, int> position;
    int boardWidth;
    int boardHeight;

public:
    Food(int boardWidth, int boardHeight);
    ~Food();
    
    void generateNewPosition();
    void generateNewPosition(const std::vector<std::pair<int, int>>& snakeBody);
    
    std::pair<int, int> getPosition() const;
    bool isEaten(const std::pair<int, int>& snakeHead) const;
    
    void setBoardSize(int width, int height);
};

#endif // FOOD_HPP