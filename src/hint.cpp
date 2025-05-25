#include "coursework.hpp"
#include <map>

// подсказываем самую редко повторяющуюся букву
void Game::giveHintLetter() {
    std::map<char, int> frequency;

    // считаем сколько раз повторяются буквы
    for (char ch : currentWord) {
        frequency[ch]++;
    }

    char revLetter = '\0';
    int minFreq = INT_MAX;

    // находим минимум повторов
    for (const auto& [letter, count] : frequency) {
        if (displayWord.find(letter) != std::string::npos)
            continue;

        if (count < minFreq) {
            minFreq = count;
            revLetter = letter;
        }
    }

    // добавляем эту букву в то, что выведено
    if (revLetter != '\0') {
        for (std::size_t i = 0; i < currentWord.length(); ++i) {
            if (currentWord[i] == revLetter) {
                displayWord[i] = revLetter;
            }
        }

        updateWordDisplay();

        // проверям, произошел ли выигрыш
        if (displayWord == currentWord) {
            isGameWon = true;
            isGameOver = true;
            endingGameText.setFillColor(sf::Color::White);
            endingGame();
        }
    }
}
