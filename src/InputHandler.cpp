#include "InputHandler.hpp"
#include <iostream>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

// TODO: Implémenter le constructeur
InputHandler::InputHandler() {
    // Initialiser les variables
}

// TODO: Implémenter le destructeur
InputHandler::~InputHandler() {
    // Restaurer les paramètres de la console
}

// TODO: Implémenter le traitement des entrées
void InputHandler::processInput(Snake& snake) {
    // Lire les touches et modifier la direction du serpent
}

// TODO: Implémenter les getters
bool InputHandler::isExitRequested() const {
    return exitRequested;
}

void InputHandler::reset() {
    exitRequested = false;
}

// TODO: Implémenter la lecture de touche (Windows)
char InputHandler::getKeyPress() {
#ifdef _WIN32
    // Utiliser _kbhit() et _getch() sur Windows
    return 0;
#else
    // Utiliser termios sur Linux/Mac
    return 0;
#endif
}

// TODO: Implémenter le mode raw (pour lecture immédiate)
void InputHandler::enableRawMode() {
#ifdef _WIN32
    // Configuration Windows
#else
    // Configuration Unix/Linux
#endif
}

void InputHandler::disableRawMode() {
#ifdef _WIN32
    // Restauration Windows
#else
    // Restauration Unix/Linux
#endif
}