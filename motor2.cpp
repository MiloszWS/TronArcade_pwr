//
// Created by pmi03 on 05.06.2023.
//
#include "motor2.h"

using namespace std;

motor2 :: motor2(boardTextView & board2, GameMode2 mode) :board(board2){

        int motor = board.getBoardWidth()*(board.getBoardHeight()/2)+(board.getBoardWidth()/3)+(board.getBoardWidth()/3);
        motorcycle2.push_back(motor);

        for (int i = 0; i < motorcycle2.size(); i++) {
            board.board[motorcycle2[i]] = 2;
        }
}

void motor2 ::moveStraight() {

        int head = motorcycle2.front();
        int afterhead=head;
        int tail = motorcycle2.back();
        board.board[tail] = 4;

        switch (direction) {
            case RIGHT2:
                head += 1;
                break;
            case UP2:
                head -= board.getBoardWidth();
                break;
            case LEFT2:
                head -= 1;
                break;
            case DOWN2:
                head += board.getBoardWidth();
                break;
            case STAY2:
                head = head;
                break;
        }

        board.board[head] = 2;
        if (motorcycle2.size()>1){
            board.board[afterhead] = 4;
        }
        motorcycle2.insert(motorcycle2.begin(), head);
}

void motor2 ::turnRight() {
    if (direction!=LEFT2) direction = RIGHT2;
}
void motor2 ::turnLeft() {
    if (direction!=RIGHT2) direction = LEFT2;
}
void motor2 ::goUp() {
    if (direction!=DOWN2) direction = UP2;
}
void motor2 ::goDown() {
    if (direction!=UP2) direction = DOWN2;
}