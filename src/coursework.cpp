#include <cstdint>
#include "coursework.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

// что делает запуск игры; обрабатываем процессы и обновляем происходящее
void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

// создаем и запускаем игру
int main() {
    Game game;
    game.run();
    return 0;
}
