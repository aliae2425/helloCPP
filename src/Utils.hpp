#ifndef UTILS_HPP
#define UTILS_HPP

#include <chrono>
#include <string>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point lastTime;
    int targetFPS;

public:
    Timer(int fps = 10);
    ~Timer();
    
    void setFPS(int fps);
    bool shouldUpdate();
    void reset();
    void wait();
};

class Console {
public:
    static void clear();
    static void gotoxy(int x, int y);
    static void hideCursor();
    static void showCursor();
    static void setColor(int color);
    static void resetColor();
    
    // Fonctions spécifiques à Windows
    #ifdef _WIN32
    static void setupConsole();
    static void restoreConsole();
    #endif
};

class Random {
public:
    static int range(int min, int max);
    static void seed();
};

#endif // UTILS_HPP