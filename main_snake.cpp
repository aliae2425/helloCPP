#include <iostream>
#include "src/Game.hpp"
#include "src/Utils.hpp"

int main() {
    try {
        // Configuration de la console
        #ifdef _WIN32
        Console::setupConsole();
        #endif
        
        Console::hideCursor();
        
        // TODO: Créer et lancer le jeu
        const int BOARD_WIDTH = 20;
        const int BOARD_HEIGHT = 15;
        
        Game snakeGame(BOARD_WIDTH, BOARD_HEIGHT);
        
        std::cout << "=== SNAKE GAME ===" << std::endl;
        std::cout << "Utilisez ZQSD ou les flèches pour jouer" << std::endl;
        std::cout << "Appuyez sur une touche pour commencer..." << std::endl;
        std::cin.get();
        
        snakeGame.run();
        
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }
    
    // Restaurer la console
    Console::showCursor();
    #ifdef _WIN32
    Console::restoreConsole();
    #endif
    
    std::cout << "Merci d'avoir joué!" << std::endl;
    return 0;
}