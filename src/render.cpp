#include "coursework.hpp"

void Game::render() {
    // очищаем окно и заливаем его цветом
    window.clear(sf::Color(199, 159, 239));

    if (isGameOver) { // если игра завершена
        window.draw(lavenderSprite); // лаванда
        // в зависимости от результата игры выводим текст
        if (isGameWon) {
            window.draw(winText);
            window.draw(correctWordText);
        }
        else {
            window.draw(correctWordText);
            window.draw(endingGameText);
        }
        // показываем restart
        if (showRestart) {
            window.draw(restartButton);
            window.draw(restartText);
        }
    }

    // если игра не начата, выводим приветственный экран
    else if (!isGameStarted) {
        window.draw(lavenderSprite);
        window.draw(welcomeText);
        window.draw(startButton);
        window.draw(startButtonText);
    }

    // если показываем выбор уровня, выводим все кнопки уровней
    else if (isDifficultyMenuShown) {
        window.draw(lavenderSprite);
        window.draw(difficultyTitleText);
        window.draw(easyButton);
        window.draw(easyButtonText);
        window.draw(mediumButton);
        window.draw(mediumButtonText);
        window.draw(hardButton);
        window.draw(hardButtonText);
    }

    // в остальных случаях идет игра
    else {
        window.draw(lavenderSprite);
        window.draw(wordDisplayText);
        window.draw(livesText);
        window.draw(wrongLettersText);
        window.draw(hintButton);
        window.draw(hintText);
    }

    window.display();
}