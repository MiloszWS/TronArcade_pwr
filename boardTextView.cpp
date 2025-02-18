//
// Created by pmi03 on 31.05.2023.
//
#include <iostream>
#include <ctime>
#include "boardTextView.h"

using namespace std;

boardTextView::boardTextView(int Width, int Height) {
    srand(time(NULL));

    width = Width;
    height = Height;
    board.resize(board.size() + width*height);
}

void boardTextView :: debug_display() const{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (board[y * width + x] == 0) {
                if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                    cout << " W ";  // pole na granicy planszy
                } else cout << "   ";  // puste pole
            } else if (board[y * width + x] == 1) {
                cout << " 1 ";  // pozycja gracza
            } else if (board[y * width + x] == 2) {
                cout << " 2 ";  // pozycja gracza2
            } else if (board[y * width + x] == 3) {
                cout << " ! ";  //smuga gracza1
            } else if (board[y * width + x] == 4) {
                cout << " ! ";  //smuga gracza2/bota
            }
        }
        cout << endl;
    }

}

int boardTextView ::getBoardWidth() const {
    return width;
}

int boardTextView ::getBoardHeight() const {
    return height;
}

char boardTextView ::getFieldInfo(int x, int y) const{
    int width=getBoardWidth();
    int height=getBoardHeight();
    if (board[y * width + x] == 1) { // Gracz1
        return 'P';
    } else if (board[y * width + x] == 2) { // Gracz2
        return 'p';
    } else if (board[y * width + x] == 3) { // smuga gracza1
        return 'S';
    } else if (board[y * width + x] == 4) { // smuga gracza2/bota
        return 's';
    } else if (x == 1 || x == width - 2 || y == 1 || y == height - 2) { // ściana
        return '#';
    } else { // puste pole
        return ' ';
    }
}

void boardTextView :: display() const {
    for (int i = 0; i < getBoardHeight(); i++) {
        for (int j = 0; j < getBoardWidth(); j++) {
            cout << " " << getFieldInfo(j, i) << " ";
        }
        cout << endl;
    }
}