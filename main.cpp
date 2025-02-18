
#include "boardTextView.h"
#include "motorsTextView.h"
#include "SFMLController.h"
#include "Integrator.h"
#include "menuScreen.h"
#include "modeChoose.h"
#include "SFMLView.h"
#include "motor2.h"


int main() {
    boardTextView board(70, 70);
    motorsTextView motor1(board, EASY);
    motor2 motor2(board, EASY2);
    SFMLView view(board);
    Integrator integer(motor1, motor2, board);
    menuScreen menu(board);
    modeChoose modeScreen(board);
    SFMLController ctrl(motor1, motor2, view, integer, menu, modeScreen, board);
    ctrl.music();
    ctrl.play();
    return 0;
}
