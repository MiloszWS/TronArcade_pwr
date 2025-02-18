//
// Created by pmi03 on 31.05.2023.
//
#ifndef TRONARCADE_MOTORSTEXTVIEW_H
#define TRONARCADE_MOTORSTEXTVIEW_H
#include <iostream>
#include <vector>
#include "boardTextView.h"
#include <SFML/Graphics.hpp>

using namespace std;

enum Direction{UP, RIGHT, LEFT, DOWN, STAY};
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
enum GameMode { EASY, NORMAL, HARD };

class motorsTextView{
    boardTextView & board1;
public:
    motorsTextView(boardTextView & b, GameMode mode);
    void moveStraight();
    void turnRight();
    void turnLeft();
    void goUp();
    void goDown();
    bool isColliding();
    GameState getGameState();
    vector<int> motorcycle1; // Wektor motocykli dla motor1
    vector<int> motorcycle2; // Wektor motocykli dla motor2
    Direction direction;  // kierunek poruszania się motoru (0 - w górę, 1 - w prawo, 2 - w lewo)
    void update();
};

#endif //TRONARCADE_MOTORSTEXTVIEW_H
