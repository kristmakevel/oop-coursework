#include "coursework.hpp"

void Game::DifficultyMenu() {
    // текст choose a level
    difficultyTitleText.setCharacterSize(50); // размер текста
    difficultyTitleText.setFillColor(sf::Color::White); // цвет текста
    // получаем границы в координатах (x, y, длина, высота)
    sf::FloatRect titleBounds = difficultyTitleText.getLocalBounds();
    difficultyTitleText.setOrigin(titleBounds.getCenter()); // привязка
    difficultyTitleText.setPosition({ 400.f, 200.f }); // устанавливаем позицию текста

    // кнопка easy
    easyButton.setSize({ 200, 60 });
    easyButton.setFillColor(sf::Color(210, 170, 230));
    easyButton.setPosition({ 300.f, 310.f });

    // текст easy
    easyButtonText.setCharacterSize(30);
    easyButtonText.setFillColor(sf::Color::White);
    sf::FloatRect easyTextBounds = easyButtonText.getLocalBounds();
    easyButtonText.setOrigin(easyTextBounds.getCenter());
    easyButtonText.setPosition({ 400.f, 340.f });

    // кнопка medium
    mediumButton.setSize({ 200, 60 });
    mediumButton.setFillColor(sf::Color(170, 130, 230));
    mediumButton.setPosition({ 300.f, 390.f });

    // текст medium
    mediumButtonText.setCharacterSize(30);
    mediumButtonText.setFillColor(sf::Color::White);
    sf::FloatRect mediumTextBounds = mediumButtonText.getLocalBounds();
    mediumButtonText.setOrigin(mediumTextBounds.getCenter());
    mediumButtonText.setPosition({ 400.f, 420.f });

    // кнопка hard
    hardButton.setSize({ 200, 60 });
    hardButton.setFillColor(sf::Color(130, 90, 210));
    hardButton.setPosition({ 300.f, 470.f });

    // текст hard
    hardButtonText.setCharacterSize(30);
    hardButtonText.setFillColor(sf::Color::White);
    sf::FloatRect hardTextBounds = hardButtonText.getLocalBounds();
    hardButtonText.setOrigin(hardTextBounds.getCenter());
    hardButtonText.setPosition({ 400.f, 500.f });
}