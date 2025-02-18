//
// Created by pmi03 on 03.06.2023.
//
#include "menuScreen.h"

menuScreen::menuScreen(boardTextView &board1) :board(board1) {
    if (!grid.loadFromFile("D://CLion//Projects//TronArcade//Fonts//TheGrid.jpg"))//pobrane, link poniżej
    {//https://www.google.com/search?q=tron+legacy+arts&tbm=isch&ved=2ahUKEwjkq9u5l6f_AhWVtyoKHYQyB9YQ2-cCegQIABAA&oq=tron+legacy+arts&gs_lcp=CgNpbWcQAzoHCAAQExCABDoECCMQJzoHCAAQigUQQzoFCAAQgAQ6CAgAEIAEELEDOgoIABCKBRCxAxBDOgQIABAeOggIABAFEB4QEzoICAAQCBAeEBNQ7QZY2yNg6SVoAHAAeACAAVCIAcYJkgECMTeYAQCgAQGqAQtnd3Mtd2l6LWltZ8ABAQ&sclient=img&ei=-jx7ZOTGJJXvqgGE5ZywDQ&bih=722&biw=1536&rlz=1C1GCEB_enPL956PL956#imgrc=xWBKSKdN5gDPZM
        cout << "Error, it cannot load a file.\n";
    }
    sprite.setTexture(grid);

    font= sf::Font();
    font.loadFromFile("../Fonts/Modern Age.ttf");

    title.setFont(font);
    title.setString("TRON ARCADE");
    title.setCharacterSize(80); // Możesz dostosować rozmiar czcionki
    title.setFillColor(sf::Color::Black);
    title.setOutlineColor(sf::Color(0, 255, 200));
    title.setOutlineThickness(5);
    title.setStyle(sf::Text::Bold);
    title.setPosition(155,30);
    // Ustawienie pozycji i wymiarów przycisku
    buttonPlay.setPosition(350, 440);
    buttonPlay.setSize(sf::Vector2f(200, 75));
    buttonPlay.setFillColor(sf::Color::Black);
    buttonPlay.setOutlineColor(sf::Color(0, 255, 200));
    buttonPlay.setOutlineThickness(5);
// Ustawienie tekstu na przycisku
    buttonText.setFont(font);
    buttonText.setString("play");
    buttonText.setCharacterSize(50); // Możesz dostosować rozmiar czcionki
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setOutlineColor(sf::Color(0, 255, 200));
    buttonText.setOutlineThickness(5);
    buttonText.setStyle(sf::Text::Bold);
// Ustawienie pozycji tekstu w środku przycisku
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    buttonText.setPosition(350 + 200 / 2, 440 + 75 / 2);
}

void menuScreen::drawMenuScreen(sf::RenderWindow &window) {
    sprite.setScale(0.75,0.75);
    sprite.setPosition(-280,0);
    window.draw(sprite);
    window.draw(title);
    window.draw(buttonPlay);
    window.draw(buttonText);
}