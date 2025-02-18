//
// Created by pmi03 on 31.05.2023.
//
#include <iostream>
#include "motorsTextView.h"

motorsTextView :: motorsTextView(boardTextView & board2, GameMode mode) :board1(board2){

        int motor = board1.getBoardWidth()*(board1.getBoardHeight()/2)+(board1.getBoardWidth()/3);
        motorcycle1.push_back(motor);

        for (int i = 0; i < motorcycle1.size(); i++) {
            board1.board[motorcycle1[i]] = 1;
        }
}

void motorsTextView ::moveStraight() {
        int head = motorcycle1.front();
        int afterhead=head;
        int tail = motorcycle1.back();
        board1.board[tail] = 3;

        switch (direction) {
            case RIGHT:
                head += 1;
                break;
            case UP:
                head -= board1.getBoardWidth();
                break;
            case LEFT:
                head -= 1;
                break;
            case DOWN:
                head += board1.getBoardWidth();
                break;
            case STAY:
                head = head;
                break;
        }

        board1.board[head] = 1;
        if (motorcycle1.size()>1){
            board1.board[afterhead] = 3;
        }
        motorcycle1.insert(motorcycle1.begin(), head);
}

void motorsTextView ::turnRight() {
        if (direction!=LEFT) direction = RIGHT;
}
void motorsTextView ::turnLeft() {
        if (direction!=RIGHT) direction = LEFT;
}
void motorsTextView ::goUp() {
        if (direction!=DOWN) direction = UP;
}
void motorsTextView ::goDown() {
        if (direction!=UP) direction = DOWN;
}
