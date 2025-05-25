#include "coursework.hpp"
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>

// загрузка слова из файла
void Game::loadRandomWord(const std::string& filePath) {
    // считываем файлик
    std::ifstream file(filePath);
    // если не открывается, закрываем все:(
    if (!file) {
        std::cerr << "Could not open word file: " << filePath << std::endl;
        window.close();
        return;
    }

    // считываем слова и сохраняем их в вектор
    std::vector<std::string> words;
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }

    // если вектор пустой, закрываем все:(
    if (words.empty()) {
        std::cerr << "no words found in file: " << filePath << std::endl;
        window.close();
        return;
    }

    // создаем генератор случайных чисел
    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<std::size_t> dist(0, words.size() - 1);
    currentWord = words[dist(rng)]; // выбираем слово
    displayWord = std::string(currentWord.length(), '_');

    // выводим, что имеем на данный момент
    wordDisplayText.setCharacterSize(60);
    wordDisplayText.setFillColor(sf::Color::White);
    wordDisplayText.setPosition({ 50.f, 50.f });
    updateWordDisplay();

    // выводим количество жизней
    lives = 12;
    livesText.setCharacterSize(40);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition({ 50.f, 140.f });
    livesText.setString("Lives: " + std::to_string(lives));
    wrongGuesses.clear();

    // выводим неправильно отгаданные буквы
    wrongLettersText.setCharacterSize(40);
    wrongLettersText.setFillColor(sf::Color::White);
    wrongLettersText.setPosition({ 50.f, 190.f });
    wrongLettersText.setString("Wrong: ");

    // кнопка подсказки
    hintButton.setSize({ 200, 60 });
    hintButton.setFillColor(sf::Color(210, 170, 230));
    hintButton.setPosition({ 450.f, 100.f });

    // текст кнопки подсказки
    hintText.setCharacterSize(40);
    hintText.setFillColor(sf::Color::White);
    sf::FloatRect hintTextBounds = hintText.getLocalBounds();
    hintText.setOrigin(hintTextBounds.getCenter());
    hintText.setPosition({ 550.f, 130.f });

}