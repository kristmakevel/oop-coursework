#include "coursework.hpp"

void Game::ThemeMenu() {
    // вывод "choose a theme"
    themeTitleText.setCharacterSize(50);
    themeTitleText.setFillColor(sf::Color::White);
    sf::FloatRect titleBounds = themeTitleText.getLocalBounds();
    themeTitleText.setOrigin(titleBounds.getCenter());
    themeTitleText.setPosition({ 400.f, 100.f });

    //кнопка и текст animals
    animalButton.setSize({ 200, 60 });
    animalButton.setFillColor(sf::Color(180, 140, 230));
    animalButton.setPosition({ 300.f, 290.f });

    animalText.setCharacterSize(30);
    animalText.setFillColor(sf::Color::White);
    sf::FloatRect animalTextBounds = animalText.getLocalBounds();
    animalText.setOrigin(animalTextBounds.getCenter());
    animalText.setPosition({ 400.f, 320.f });

    // кнопка и текст random
    randomsButton.setSize({ 200, 60 });
    randomsButton.setFillColor(sf::Color(150, 110, 210));
    randomsButton.setPosition({ 300.f, 370.f });

    randomsText.setCharacterSize(30);
    randomsText.setFillColor(sf::Color::White);
    sf::FloatRect randomsTextBounds = randomsText.getLocalBounds();
    randomsText.setOrigin(randomsTextBounds.getCenter());
    randomsText.setPosition({ 400.f, 400.f });

    // кнопка и текст science

    scienceButton.setSize({ 200, 60 });
    scienceButton.setFillColor(sf::Color(120, 85, 190));
    scienceButton.setPosition({ 300.f, 450.f });

    scienceText.setCharacterSize(30);
    scienceText.setFillColor(sf::Color::White);
    sf::FloatRect scienceTextBounds = scienceText.getLocalBounds();
    scienceText.setOrigin(scienceTextBounds.getCenter());
    scienceText.setPosition({ 400.f, 480.f });

    // кнопка и текст books

    bookButton.setSize({ 200, 60 });
    bookButton.setFillColor(sf::Color(90, 60, 170));
    bookButton.setPosition({ 300.f, 530.f });

    bookText.setCharacterSize(30);
    bookText.setFillColor(sf::Color::White);
    sf::FloatRect bookTextBounds = bookText.getLocalBounds();
    bookText.setOrigin(bookTextBounds.getCenter());
    bookText.setPosition({ 400.f, 560.f });
}