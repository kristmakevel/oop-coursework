#include "coursework.hpp"
#include <map>

void Game::processEvents() {
    // пока что-то происходит
    while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close(); // закрываем
        }

        // если нажимают курсор
        if (isGameOver && event->is<sf::Event::MouseButtonPressed>()) {
            auto mousePos = sf::Mouse::getPosition(window); // координаты нажатия в окне
            sf::Vector2f pos = { static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) };
            if (restartButton.getGlobalBounds().contains(pos)) { // если нажимаем на рестарт
                // сбрасываем все
                isGameStarted = false;
                isDifficultyMenuShown = false;
                isGameOver = false;
                isGameWon = false;
                wrongGuesses.clear();
                currentWord.clear();
                displayWord.clear();
                lives = 12;
                hints = 3;
                wordDisplayText.setString("");
                wrongLettersText.setString("Wrong: ");
                livesText.setString("Lives: 12");
                showRestart = false;
            }
        }

        if (!isGameStarted && event->is<sf::Event::MouseButtonPressed>()) { // если игра не начата
            auto mousePos = sf::Mouse::getPosition(window);
            // если попадает на кнопку старт
            if (startButton.getGlobalBounds().contains({ static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) })) {
                // запускаем игру
                isGameStarted = true;
                isDifficultyMenuShown = true;
                DifficultyMenu();
            }
        }

        else if (isDifficultyMenuShown && event->is<sf::Event::MouseButtonPressed>()) { // если выбираем сложность
            auto mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f pos = { static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) };
            // в зависимости от выбранного уровня загружаем слово из нужного файла
            if (easyButton.getGlobalBounds().contains(pos)) {
                isDifficultyMenuShown = false;
                isThemeMenuShown = true;
                level = "easy";
                ThemeMenu();
            }
            else if (mediumButton.getGlobalBounds().contains(pos)) {
                level = "medium";
                isDifficultyMenuShown = false;
                isThemeMenuShown = true;
                ThemeMenu();
            }
            else if (hardButton.getGlobalBounds().contains(pos)) {
                level = "hard";
                isDifficultyMenuShown = false;
                isThemeMenuShown = true;
                ThemeMenu();
            }
        }

        else if (isThemeMenuShown && event->is<sf::Event::MouseButtonPressed>()) {
            auto mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f pos = { static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) };
            if (animalButton.getGlobalBounds().contains(pos)) {
                std::string path = "words/" + level + "/" + "animal.txt";
                isThemeMenuShown = false;
                loadRandomWord(path);
            }
            else if (randomsButton.getGlobalBounds().contains(pos)) {
                std::string path = "words/" + level + "/" + "randoms.txt";
                isThemeMenuShown = false;
                loadRandomWord(path);
            }
            else if (scienceButton.getGlobalBounds().contains(pos)) {
                std::string path = "words/" + level + "/" + "science.txt";
                isThemeMenuShown = false;
                loadRandomWord(path);
            }
            else if (bookButton.getGlobalBounds().contains(pos)) {
                std::string path = "words/" + level + "/" + "book.txt";
                isThemeMenuShown = false;
                loadRandomWord(path);
            }
        }

        else if (isGameStarted && event->is<sf::Event::MouseButtonPressed>()) { // если в процессе игры нажатие
            auto mousePos = sf::Mouse::getPosition(window); // если попадает на кнопку подсказки
            sf::Vector2f pos = { static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) };
            if (hintButton.getGlobalBounds().contains(pos)) {
                if (hints > 0) {
                    giveHintLetter(); // даем подсказку
                    hints--;
                }
            }
        }

        else if (!isDifficultyMenuShown && !isGameOver && event->is<sf::Event::TextEntered>()) { // ввод в игре
            if (const auto* textEvent = event->getIf<sf::Event::TextEntered>()) {
                char typedChar = static_cast<char>(textEvent->unicode);

                if (std::isalpha(typedChar)) { // если это буква
                    typedChar = static_cast<char>(std::tolower(typedChar));

                    // если буква уже в неправильных или уже раскрыта
                    if (wrongGuesses.find(typedChar) != std::string::npos || displayWord.find(typedChar) != std::string::npos)
                        return;

                    // пробегаемся по слову и ищем букву
                    bool found = false;
                    for (std::size_t i = 0; i < currentWord.length(); ++i) {
                        if (currentWord[i] == typedChar) {
                            displayWord[i] = typedChar;
                            found = true;
                        }
                    }

                    if (!found) { // если не нашлась
                        wrongGuesses += typedChar;
                        wrongLettersText.setString("Wrong: " + wrongGuesses);
                        lives--;

                        if (lives == 0) { // если жизни закончились, выводим проигрыш
                            isGameOver = true;
                            isGameWon = false;
                            endingGame();
                        }

                        livesText.setString("Lives: " + std::to_string(lives));
                    }
                    updateWordDisplay();

                    // если слово отгадано, выводим выигрыш
                    if (displayWord == currentWord) {
                        isGameWon = true;
                        isGameOver = true;
                        endingGameText.setFillColor(sf::Color::White);
                        endingGame();
                    }

                }
            }
        }
    }
}