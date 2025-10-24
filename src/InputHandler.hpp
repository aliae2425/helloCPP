#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "Snake.hpp"

class InputHandler {
private:
    bool exitRequested;

public:
    InputHandler();
    ~InputHandler();
    
    void processInput(Snake& snake);
    bool isExitRequested() const;
    void reset();
    
    // Fonctions spécifiques à la plateforme
    char getKeyPress();
    void enableRawMode();
    void disableRawMode();
};

#endif // INPUT_HANDLER_HPP