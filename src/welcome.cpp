#include "coursework.hpp"
#include <iostream>

// приветственный экран
void Game::WelcomeScreen() {
    // возможные пути, где лежит шрифт
    const std::vector<std::string> fontPaths = {
        "assets/fonts/arial.ttf",
        "C:/Windows/Fonts/arial.ttf"
    };

    bool fontLoaded = false;

    // пытаемся загрузить шрифт
    for (const auto& path : fontPaths) {
        try {
            if (font.openFromFile(path)) {
                fontLoaded = true;
                break;
            }
        }
        catch (const std::exception& some_exception) {
            std::cerr << "an exception while loading font: " << some_exception.what() << std::endl;
        }
    }

    // если не загружается, закрываем все:(
    if (!fontLoaded) {
        std::cerr << "error: failed to load font:(\n";
        window.close();
        return;
    }

    // вывод guess the word
    welcomeText.setCharacterSize(60);
    welcomeText.setFillColor(sf::Color::White);
    welcomeText.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = welcomeText.getLocalBounds();
    welcomeText.setOrigin(textRect.getCenter());
    welcomeText.setPosition({ 400.f, 100.f });

    // кнопка start
    startButton.setSize({ 200, 80 });
    startButton.setFillColor(sf::Color(81, 0, 99));
    startButton.setOutlineThickness(0);
    startButton.setPosition({ 300.f, 190.f });

    // текст start
    startButtonText.setCharacterSize(40);
    startButtonText.setFillColor(sf::Color::White);
    sf::FloatRect buttonTextRect = startButtonText.getLocalBounds();
    startButtonText.setOrigin(buttonTextRect.getCenter());
    startButtonText.setPosition({ 400.f, 230.f });

    isDifficultyMenuShown = false;
}