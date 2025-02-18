//
// Created by pmi03 on 06.06.2023.
//
#include "modeChoose.h"

modeChoose::modeChoose(boardTextView &board1) :board(board1) {
    if (!grid.loadFromFile("D://CLion//Projects//TronArcade//Fonts//TheGrid.jpg"))//pobrane, link poniżej
    {//https://www.google.com/search?q=tron+legacy+arts&tbm=isch&ved=2ahUKEwjkq9u5l6f_AhWVtyoKHYQyB9YQ2-cCegQIABAA&oq=tron+legacy+arts&gs_lcp=CgNpbWcQAzoHCAAQExCABDoECCMQJzoHCAAQigUQQzoFCAAQgAQ6CAgAEIAEELEDOgoIABCKBRCxAxBDOgQIABAeOggIABAFEB4QEzoICAAQCBAeEBNQ7QZY2yNg6SVoAHAAeACAAVCIAcYJkgECMTeYAQCgAQGqAQtnd3Mtd2l6LWltZ8ABAQ&sclient=img&ei=-jx7ZOTGJJXvqgGE5ZywDQ&bih=722&biw=1536&rlz=1C1GCEB_enPL956PL956#imgrc=xWBKSKdN5gDPZM
        cout << "Error, it cannot load a file.\n";
    }
    sprite.setTexture(grid);

    font= sf::Font();
    font.loadFromFile("../Fonts/Modern Age.ttf");

    title.setFont(font);
    title.setString("CHOOSE GAMEMODE");
    title.setCharacterSize(60); // Możesz dostosować rozmiar czcionki
    title.setFillColor(sf::Color::Black);
    title.setOutlineColor(sf::Color(0, 255, 200));
    title.setOutlineThickness(5);
    title.setStyle(sf::Text::Bold);
    title.setPosition(130,30);
    
    // Ustawienie pozycji i wymiarów przycisku
    buttonMulti.setPosition(60, 440);
    buttonMulti.setSize(sf::Vector2f(300, 75));
    buttonMulti.setFillColor(sf::Color::Black);
    buttonMulti.setOutlineColor(sf::Color(0, 255, 200));
    buttonMulti.setOutlineThickness(5);
// Ustawienie tekstu na przycisku
    textMulti.setFont(font);
    textMulti.setString("multiplayer");
    textMulti.setCharacterSize(40); // Możesz dostosować rozmiar czcionki
    textMulti.setFillColor(sf::Color::Black);
    textMulti.setOutlineColor(sf::Color(0, 255, 200));
    textMulti.setOutlineThickness(5);
    textMulti.setStyle(sf::Text::Bold);
// Ustawienie pozycji tekstu w środku przycisku
    sf::FloatRect textBounds = textMulti.getLocalBounds();
    textMulti.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    textMulti.setPosition(60 + 300 / 2, 440 + 75 / 2);

    // Ustawienie pozycji i wymiarów przycisku
    buttonSingle.setPosition(550, 440);
    buttonSingle.setSize(sf::Vector2f(300, 75));
    buttonSingle.setFillColor(sf::Color::Black);
    buttonSingle.setOutlineColor(sf::Color(0, 255, 200));
    buttonSingle.setOutlineThickness(5);
// Ustawienie tekstu na przycisku
    textSingle.setFont(font);
    textSingle.setString("singleplayer");
    textSingle.setCharacterSize(40); // Możesz dostosować rozmiar czcionki
    textSingle.setFillColor(sf::Color::Black);
    textSingle.setOutlineColor(sf::Color(0, 255, 200));
    textSingle.setOutlineThickness(5);
    textSingle.setStyle(sf::Text::Bold);
// Ustawienie pozycji tekstu w środku przycisku
    sf::FloatRect textBounds2 = textSingle.getLocalBounds();
    textSingle.setOrigin(textBounds2.left + textBounds2.width / 2, textBounds2.top + textBounds2.height / 2);
    textSingle.setPosition(550 + 300 / 2, 440 + 75 / 2);
}

void modeChoose::drawChooseScreen(sf::RenderWindow &window) {
    sprite.setScale(0.75,0.75);
    sprite.setPosition(-280,0);
    window.draw(sprite);
    window.draw(title);
    window.draw(buttonSingle);
    window.draw(textSingle);
    window.draw(buttonMulti);
    window.draw(textMulti);
}