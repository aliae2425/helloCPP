#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <utility>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
private:
    std::vector<std::pair<int, int>> body;
    Direction currentDirection;
    Direction nextDirection;
    bool hasEaten;

public:
    Snake(int startX, int startY);
    ~Snake();
    
    void move();
    void changeDirection(Direction newDirection);
    void grow();
    void reset(int startX, int startY);
    
    bool checkSelfCollision() const;
    bool checkWallCollision(int boardWidth, int boardHeight) const;
    
    std::pair<int, int> getHead() const;
    const std::vector<std::pair<int, int>>& getBody() const;
    int getSize() const;
    Direction getCurrentDirection() const;
};

#endif // SNAKE_HPP