#include "coursework.hpp"

// обновления слов (___) с пробелами
void Game::updateWordDisplay() {
    std::string spaced;
    for (char c : displayWord) {
        spaced += c;
        spaced += ' ';
    }
    wordDisplayText.setString(spaced);
}

void Game::update() {
}