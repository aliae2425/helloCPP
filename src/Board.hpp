#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <utility>

enum class CellType {
    EMPTY,
    SNAKE_HEAD,
    SNAKE_BODY,
    FOOD,
    WALL
};

class Board {
private:
    int width;
    int height;
    std::vector<std::vector<CellType>> grid;

public:
    Board(int width, int height);
    ~Board();
    
    void clear();
    void update(const std::vector<std::pair<int, int>>& snakeBody, 
                const std::pair<int, int>& foodPosition);
    void render() const;
    void renderWithBorders() const;
    
    void setCell(int x, int y, CellType type);
    CellType getCell(int x, int y) const;
    
    int getWidth() const;
    int getHeight() const;
    
    bool isValidPosition(int x, int y) const;
};

#endif // BOARD_HPP