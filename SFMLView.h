//
// Created by pmi03 on 31.05.2023.
//
#include <SFML/Graphics.hpp>
#include "boardTextView.h"
#include "motorsTextView.h"
#include "motor2.h"
#include <SFML/System/Clock.hpp>


#ifndef TRONARCADE_SFMLVIEW_H
#define TRONARCADE_SFMLVIEW_H

class SFMLView {
    boardTextView &board;
    sf::RectangleShape field;
    sf:: Font font;

public:
    SFMLView(boardTextView & board1);
    void draw(sf:: RenderWindow & window);
    void setScoreMotor1(int score);
    void setScoreMotor2(int score);
   sf::Text LetsPlay, GameOver1, GameOver2, player1, player2, score1, score2, pressSpace, Draw;
   int scoreMotor1, scoreMotor2;


};
#endif //TRONARCADE_SFMLVIEW_H
