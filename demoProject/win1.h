#ifndef TESTPROJECT_WIN1_H
#define TESTPROJECT_WIN1_H

#include "../include/Window.h"
#include "../include/Button.h"
#include "../include/TextBlock.h"
#include "../include/Toggle.h"

class win1 : public Window {
public:
    win1();

    WindowProcessResult processInput(int input) override;

private:
    Button *_win2Btn;
    Button *_quitBtn;
    TextBlock *_title;
    Toggle *_toggle1;
    Toggle *_toggle2;
    bool openWin2 = false;
};

#endif  // TESTPROJECT_WIN1_H
