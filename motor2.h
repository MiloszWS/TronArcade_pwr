//
// Created by pmi03 on 05.06.2023.
//

#ifndef TRONARCADE_MOTOR2_H
#define TRONARCADE_MOTOR2_H
#include <iostream>
#include <vector>
#include "boardTextView.h"
#include <SFML/Graphics.hpp>

enum Direction2{UP2, RIGHT2, LEFT2, DOWN2, STAY2};
enum GameState2 { RUNNING2, FINISHED_WIN2, FINISHED_LOSS2 };
enum GameMode2 { EASY2, NORMAL2, HARD2 };

class motor2{
protected:
    boardTextView & board;
public:
    motor2(boardTextView & b, GameMode2 mode);
    void moveStraight();
    void turnRight();
    void turnLeft();
    void goUp();
    void goDown();
    vector<int> motorcycle2; // Wektor motocykli dla motor2
    Direction2 direction;  // kierunek poruszania się motoru (0 - w górę, 1 - w prawo, 2 - w lewo)
    void update();
};

#endif //TRONARCADE_MOTOR2_H
