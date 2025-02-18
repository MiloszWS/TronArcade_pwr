//
// Created by pmi03 on 03.06.2023.
//
#include "Integrator.h"
using namespace std;

Integrator::Integrator(motorsTextView &motor11, class motor2& motor22, boardTextView &board): board(board), motor1(motor11), motor2(motor22) {
}

bool Integrator::isColliding1() {
    int head = motor1.motorcycle1.front();
    if (motor1.motorcycle1.size() > 10) {
        for (int i = 1; i < motor1.motorcycle1.size(); i++) {
            if (head ==motor1.motorcycle1[i]) {
                board.whichOne=1;
                return true;
            } if (head ==motor2.motorcycle2[i]){
                board.whichOne=1;
                return true;
            }
        }
    }

    int x = head % board.getBoardWidth();
    int y = head / board.getBoardWidth();
    if (x < 2 || x >= board.getBoardWidth()-2 || y < 2 || y >= board.getBoardHeight()-2) {
        board.whichOne=1;
        return true;
    }
    return false;
}

bool Integrator::isColliding2() {
    int head2 = motor2.motorcycle2.front();
    if (motor2.motorcycle2.size() > 10) {
        for (int i = 1; i < motor2.motorcycle2.size(); i++) {
            if (head2 ==motor2.motorcycle2[i]) {
                board.whichOne=2;
               return true;
            }
            if (head2 ==motor1.motorcycle1[i]){
                board.whichOne=2;
                return true;
            }
        }
    }
    int x2 = head2 % board.getBoardWidth();
    int y2 = head2 / board.getBoardWidth();
    if (x2 < 2 || x2 >= board.getBoardWidth()-2 || y2 < 2 || y2 >= board.getBoardHeight()-2) {
        board.whichOne=2;
        return true;
    }
    return false;
}

GameState Integrator ::getGameState1() {
    if (isColliding1()) {
        again=1;
        if (isColliding2()){
            board.whichOne=3;
        }
        return FINISHED_LOSS;
    } else  return RUNNING;
}

GameState2 Integrator ::getGameState2() {
    if (isColliding2()) {
        again = 1;
        if (isColliding1()){
            board.whichOne=3;
        }
        return FINISHED_LOSS2;
    } else  return RUNNING2;
}

void Integrator::update() {
    if (getGameState1()==RUNNING){
        motor1.moveStraight();
    }
    if (getGameState2()==RUNNING2){
        motor2.moveStraight();
    }
}

void Integrator::resetGame() {
    motor1.motorcycle1.clear();
    motor2.motorcycle2.clear();

    for (int i = 0; i < board.board.size(); ++i) {
            board.board[i]=0;
    }
    motor1.direction=UP;
    motor2.direction=UP2;
    board.whichOne=0;

    int motor = board.getBoardWidth()*(board.getBoardHeight()/2)+(board.getBoardWidth()/3);
    motor1.motorcycle1.push_back(motor);

    for (int i = 0; i < motor1.motorcycle1.size(); i++) {
        board.board[motor1.motorcycle1[i]] = 1;
    }

    int motor22 = board.getBoardWidth()*(board.getBoardHeight()/2)+(board.getBoardWidth()/3)+(board.getBoardWidth()/3);
    motor2.motorcycle2.push_back(motor22);

    for (int i = 0; i < motor2.motorcycle2.size(); i++) {
        board.board[motor2.motorcycle2[i]] = 2;
    }

    for (int i = 0; i < board.getBoardWidth(); ++i) {
        for (int j = 0; j < board.getBoardHeight(); ++j) {
            board.getFieldInfo(i, j);
        }
    }
}