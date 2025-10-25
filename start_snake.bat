@echo off
echo Lancement du Snake Game...
echo.
cd /d "%~dp0"
build\SnakeGame.exe
echo.
echo Appuyez sur une touche pour fermer...
pause >nul