#include "coursework.hpp"

void Game::endingGame() {
    // если игра выиграна, выводим поздравление
    if (isGameWon) {
        winText.setCharacterSize(50);
        winText.setFillColor(sf::Color::White);
        sf::FloatRect winTextBounds = winText.getLocalBounds();
        winText.setOrigin(winTextBounds.getCenter());
        winText.setPosition({ 400.f, 150.f });
    }

    // если проиграна, выводим i'm sorry 
    else {
        endingGameText.setCharacterSize(50);
        endingGameText.setFillColor(sf::Color::White);
        sf::FloatRect endingTextBounds = endingGameText.getLocalBounds();
        endingGameText.setOrigin(endingTextBounds.getCenter());
        endingGameText.setPosition({ 400.f, 150.f });
    }

    // выводим правильное слово
    correctWordText.setString("correct word: " + currentWord);
    correctWordText.setCharacterSize(50);
    correctWordText.setFillColor(sf::Color::White);
    sf::FloatRect correctWordBounds = correctWordText.getLocalBounds();
    correctWordText.setOrigin(correctWordBounds.getCenter());
    correctWordText.setPosition({ 400.f, 50.f });

    // в любом случае выводим кнопку restart
    restartButton.setSize({ 200, 60 });
    restartButton.setFillColor(sf::Color(80, 0, 89));
    restartButton.setPosition({ 300.f, 200.f });

    // текст restart
    restartText.setCharacterSize(30);
    restartText.setFillColor(sf::Color::White);
    sf::FloatRect restartTextBounds = restartText.getLocalBounds();
    restartText.setOrigin(restartTextBounds.getCenter());
    restartText.setPosition({ 400.f, 230.f });

    showRestart = true;
}