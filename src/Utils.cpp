#include "Utils.hpp"
#include <iostream>
#include <random>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

// ========== Timer Class ==========

// TODO: Implémenter le constructeur Timer
Timer::Timer(int fps) {
    // Initialiser le timer avec FPS
}

Timer::~Timer() {
    // Destructeur
}

void Timer::setFPS(int fps) {
    targetFPS = fps;
}

// TODO: Implémenter shouldUpdate
bool Timer::shouldUpdate() {
    // Vérifier si assez de temps s'est écoulé
    return false;
}

void Timer::reset() {
    lastTime = std::chrono::high_resolution_clock::now();
}

// TODO: Implémenter wait
void Timer::wait() {
    // Attendre pour maintenir le FPS
}

// ========== Console Class ==========

void Console::clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Console::gotoxy(int x, int y) {
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\033[%d;%dH", y + 1, x + 1);
#endif
}

void Console::hideCursor() {
#ifdef _WIN32
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
#else
    printf("\e[?25l");
#endif
}

void Console::showCursor() {
#ifdef _WIN32
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
#else
    printf("\e[?25h");
#endif
}

// TODO: Implémenter setColor
void Console::setColor(int color) {
#ifdef _WIN32
    // SetConsoleTextAttribute
#else
    // Séquences ANSI de couleur
#endif
}

void Console::resetColor() {
    setColor(7); // Blanc par défaut
}

#ifdef _WIN32
void Console::setupConsole() {
    // Configurer l'UTF-8 pour la console Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // Améliorer l'affichage
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void Console::restoreConsole() {
    // Restaurer les paramètres originaux
    SetConsoleOutputCP(GetACP());
    SetConsoleCP(GetACP());
}
#endif

// ========== Random Class ==========

int Random::range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void Random::seed() {
    srand(time(nullptr));
}