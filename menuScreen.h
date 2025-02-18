//
// Created by pmi03 on 03.06.2023.
//

#ifndef TRONARCADE_MENUSCREEN_H
#define TRONARCADE_MENUSCREEN_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "boardTextView.h"
#include "motorsTextView.h"
#include "SFMLview.h"

class menuScreen{
    boardTextView & board;

public:

    sf:: Font font;
    sf::RectangleShape field, buttonPlay;
    sf::Text buttonText, title;
    sf:: Texture grid;
    sf:: Sprite sprite;
    menuScreen(boardTextView & board1);
    void drawMenuScreen(sf:: RenderWindow & window);


    bool isScreen1 = true;
};
#endif //TRONARCADE_MENUSCREEN_H
