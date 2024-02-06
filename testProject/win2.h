
#ifndef CONSOLEINTERACTIVEENGINE_WIN2_H
#define CONSOLEINTERACTIVEENGINE_WIN2_H


#include "../include/Window.h"
#include "../include/TextBlock.h"
#include "../include/Slider.h"

class win2 : public Window {
public:
    win2();

    WindowProcessResult processInput(int input) override;

private:
    TextBlock *label1;
    TextBlock *label2;
    Slider *slider1;
    Slider *slider2;
};


#endif //CONSOLEINTERACTIVEENGINE_WIN2_H
