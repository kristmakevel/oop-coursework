﻿#include <cstdint>
#pragma once
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void WelcomeScreen();
    void loadRandomWord(const std::string& filePath);
    void updateWordDisplay();
    void DifficultyMenu();
    void endingGame();
    void giveHintLetter();
    void ThemeMenu();

    bool isGameStarted;
    bool isDifficultyMenuShown;
    bool isGameOver;
    bool showRestart;
    bool isGameWon;
    bool isThemeMenuShown;

    int lives = 12;
    int hints = 3;

    sf::Font font;

    sf::Texture lavenderTexture;

    sf::Sprite lavenderSprite;

    sf::RenderWindow window;

    sf::Text welcomeText;
    sf::Text startButtonText;
    sf::Text difficultyTitleText;
    sf::Text easyButtonText;
    sf::Text mediumButtonText;
    sf::Text hardButtonText;
    sf::Text wordDisplayText;
    sf::Text livesText;
    sf::Text hintText;
    sf::Text restartText;
    sf::Text endingGameText;
    sf::Text wrongLettersText;
    sf::Text winText;
    sf::Text correctWordText;
    sf::Text animalText;
    sf::Text randomsText;
    sf::Text scienceText;
    sf::Text bookText;
    sf::Text themeTitleText;

    sf::RectangleShape startButton;
    sf::RectangleShape restartButton;
    sf::RectangleShape easyButton;
    sf::RectangleShape mediumButton;
    sf::RectangleShape hardButton;
    sf::RectangleShape hintButton;
    sf::RectangleShape animalButton;
    sf::RectangleShape randomsButton;
    sf::RectangleShape scienceButton;
    sf::RectangleShape bookButton;

    std::string currentWord;
    std::string displayWord;
    std::string wrongGuesses;
    std::string level;
};