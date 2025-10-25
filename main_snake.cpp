#include <iostream>
#include <locale>
#include "src/Game.hpp"
#include "src/Utils.hpp"

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#endif

void openNewTerminal() {
    #ifdef _WIN32
    // Ouvrir un nouveau terminal Windows avec le jeu
    system("start \"Snake Game\" cmd /k \"SnakeGame.exe --new-terminal\"");
    exit(0); // Fermer le terminal original
    #else
    // Pour Linux/Mac - ouvrir un nouveau terminal
    system("gnome-terminal -- ./SnakeGame --new-terminal &");
    exit(0);
    #endif
}

int main(int argc, char* argv[]) {
    // Par défaut, lancer directement le jeu (plus simple)
    // Si l'utilisateur veut un nouveau terminal, il peut utiliser l'argument --new-terminal-mode
    bool shouldOpenNewTerminal = false;
    if (argc > 1 && std::string(argv[1]) == "--new-terminal-mode") {
        shouldOpenNewTerminal = true;
    }
    
    if (shouldOpenNewTerminal) {
        openNewTerminal();
        return 0;
    }
    
    try {
        // Configuration UTF-8
        #ifdef _WIN32
        // Configuration pour Windows
        Console::setupConsole();
        #else
        // Configuration pour Linux/Mac
        std::setlocale(LC_ALL, "en_US.UTF-8");
        #endif
        
        Console::clear();
        Console::hideCursor();
        
        const int BOARD_WIDTH = 20;
        const int BOARD_HEIGHT = 15;
        
        Game snakeGame(BOARD_WIDTH, BOARD_HEIGHT);
        
        std::cout << "🐍 === SNAKE GAME === 🐍" << std::endl;
        std::cout << "🎮 Utilisez ZQSD ou les flèches pour jouer" << std::endl;
        std::cout << "🍎 Mangez les pommes pour grandir!" << std::endl;
        std::cout << "⌨️  Appuyez sur une touche pour commencer..." << std::endl;
        std::cin.get();
        
        snakeGame.run();
        
    } catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << std::endl;
    }
    
    // Restaurer la console
    Console::showCursor();
    #ifdef _WIN32
    Console::restoreConsole();
    #endif
    
    std::cout << "🎉 Merci d'avoir joué au Snake Game!" << std::endl;
    std::cout << "Appuyez sur une touche pour fermer..." << std::endl;
    std::cin.get();
    
    return 0;
}