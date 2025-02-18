//
// Created by pmi03 on 06.06.2023.
//

#ifndef TRONARCADE_MODECHOOSE_H
#define TRONARCADE_MODECHOOSE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "boardTextView.h"
#include "motorsTextView.h"
#include "SFMLview.h"

class modeChoose{
    boardTextView & board;

public:

    sf:: Font font;
    sf::RectangleShape field, buttonMulti, buttonSingle;
    sf::Text textMulti, textSingle, title;
    sf:: Texture grid;
    sf:: Sprite sprite;
    modeChoose(boardTextView & board1);
    void drawChooseScreen(sf:: RenderWindow & window);

    bool isScreen2 = true;
};
#endif //TRONARCADE_MODECHOOSE_H
