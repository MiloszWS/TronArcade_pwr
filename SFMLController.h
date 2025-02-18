//
// Created by pmi03 on 01.06.2023.
//

#ifndef TRONARCADE_SFMLCONTROLLER_H
#define TRONARCADE_SFMLCONTROLLER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "boardTextView.h"
#include "motorsTextView.h"
#include "SFMLView.h"
#include "Integrator.h"
#include "menuScreen.h"
#include "modeChoose.h"
#include "motor2.h"

using namespace std;

class SFMLController{
public:
    sf::Event event;
    motorsTextView& motor1;
    motor2& motor2;
    SFMLView& view;
    Integrator& integer;
    menuScreen& menu;
    modeChoose& mode;
    boardTextView& board;
    SFMLController(motorsTextView& motor1, class motor2& motor2, SFMLView & view, Integrator& integer, menuScreen& menu, modeChoose& modeScreen, boardTextView& board1);
    void play();
    void runGame();
    void modeChoose();
    void music();
    bool rageQuit= false;
    int scoreMotor1 = 0; // Zmienna przechowująca wynik motoru 1
    int scoreMotor2 = 0; // Zmienna przechowująca wynik motoru 2

};

#endif //TRONARCADE_SFMLCONTROLLER_H
