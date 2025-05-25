#include "coursework.hpp"

// объявляем все; в тексте пишем сразу текст + font
Game::Game()
    : window(sf::VideoMode({ 800, 600 }), "Guess The Word"),
    font(),

    welcomeText(font, "guess the word"),
    startButtonText(font, "START"),
    difficultyTitleText(font, "choose a level"),
    easyButtonText(font, "EASY"),
    mediumButtonText(font, "MEDIUM"),
    hardButtonText(font, "HARD"),
    livesText(font, "lives:"),
    wordDisplayText(font, ""),
    wrongLettersText(font, ""),
    hintText(font, "HINT"),
    winText(font, "you won:) congrats"),
    endingGameText(font, "the game is over:( i'm sorry"),
    correctWordText(font, ""),
    restartText(font, "RESTART"),

    startButton(),
    easyButton(),
    mediumButton(),
    hardButton(),
    hintButton(),
    restartButton(),

    isGameStarted(false),
    isDifficultyMenuShown(false),
    isGameOver(false),
    showRestart(false),
    isGameWon(true),

    lavenderTexture("assets/lavender.png"),
    lavenderSprite(lavenderTexture)
{
    WelcomeScreen();
    
    sf::Vector2u textureSize = lavenderTexture.getSize(); // размер текстуры
    float desiredWidth = 800.f; // какую высоту хотим
    float scaleX = desiredWidth / textureSize.x; // во сколько раз нужно растянуть x чтоб оно подходило
    float scaleY = 0.9f * scaleX; // чуть-чуть уменьшаем чтоб оно было более растянутым
    lavenderSprite.setScale(sf::Vector2(scaleX, scaleY)); // устанавливаем во сколько раз растягиваем
    float newHeight = textureSize.y * scaleY; // новая высота
    lavenderSprite.setPosition(sf::Vector2(0.f, 600.f - newHeight)); // установка по координатам
}