@echo off
chcp 65001 >nul
cd /d "%~dp0"
echo 🐍 Lancement du Snake Game...
echo.
build\SnakeGame.exe
echo.
echo Jeu terminé! 
pause