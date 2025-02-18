//
// Created by pmi03 on 06.06.2023.
//

#ifndef TRONARCADE_EASYBOT_H
#define TRONARCADE_EASYBOT_H
#include "motor2.h"

class EASYbot : public motor2 {
public:
    EASYbot(boardTextView& board, GameMode2 mode) : motor2(board, mode) {}

    void moveRandomly() {
        // Pobierz aktualną pozycję głowy bota
        int head = motorcycle2.front();

        // Sprawdź dostępne możliwe ruchy
        std::vector<Direction2> possibleMoves;
        if (direction != LEFT2) possibleMoves.push_back(RIGHT2);
        if (direction != RIGHT2) possibleMoves.push_back(LEFT2);
        if (direction != DOWN2) possibleMoves.push_back(UP2);
        if (direction != UP2) possibleMoves.push_back(DOWN2);

        // Wybierz losowy kierunek spośród dostępnych możliwości
        int randomIndex = rand() % possibleMoves.size();
        Direction2 randomDirection = possibleMoves[randomIndex];

        // Zaktualizuj kierunek bota
        direction = randomDirection;

        // Przesuń bota na podstawie wybranego kierunku
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

        // Aktualizuj pozycję bota na planszy
        board.board[head] = 2;
        if (motorcycle2.size() > 1) {
            int afterhead = motorcycle2[1];
            board.board[afterhead] = 4;
        }
        motorcycle2.insert(motorcycle2.begin(), head);
    }

};


#endif //TRONARCADE_EASYBOT_H
