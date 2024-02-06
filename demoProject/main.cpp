#include <iostream>
#include "../include/Consolengine.h"
#include <ncurses.h>
#include "win1.h"

int main() {
    initscr();
    start_color();
    cbreak();
    noecho();
    nonl();
    keypad(stdscr, TRUE);
    curs_set(0);
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    Consolengine engine(new win1());
    engine.run();
    getch();
    endwin();

    return 0;
}