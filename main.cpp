#include <winduser.h>

using namespace std;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Point d'entrée principal pour une application Windows
    // creer une fenetre 

    WINDCLASS window_class = {};
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc = DefWindowProc;

    // enregistrer la classe de fenetre

    // creer la fenetre
    return 0;
}