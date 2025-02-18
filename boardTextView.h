//
// Created by pmi03 on 31.05.2023.
//
#include <iostream>
#include <vector>
#ifndef TRONARCADE_BOARDTEXTVIEW_H
#define TRONARCADE_BOARDTEXTVIEW_H

using namespace std;

class boardTextView{
    int width;
    int height;
public:
    vector<int> board;
    boardTextView(int width, int height);
    void debug_display() const;
    int getBoardHeight() const;
    int getBoardWidth() const;
    char getFieldInfo(int x, int y) const;
    void display() const;
    int whichOne=0;
};

#endif //TRONARCADE_BOARDTEXTVIEW_H
