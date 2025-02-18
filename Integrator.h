//
// Created by pmi03 on 03.06.2023.
//

#ifndef TRONARCADE_INTEGRATOR_H
#define TRONARCADE_INTEGRATOR_H
#include <iostream>
#include "boardTextView.h"
#include "motorsTextView.h"
#include "SFMLView.h"
#include "motor2.h"

using namespace std;

class Integrator{
    boardTextView &board;
    motorsTextView& motor1;
    motor2& motor2;
    std::vector<int> motor1Motorcycle;
    std::vector<int> motor2Motorcycle;
public:
    Integrator(motorsTextView& motor1, class motor2& motor2, boardTextView &board);
    bool isColliding1();
    bool isColliding2();
    void resetGame();
    GameState getGameState1();
    GameState2 getGameState2();
    void update();
    bool again=0;

};
#endif //TRONARCADE_INTEGRATOR_H
