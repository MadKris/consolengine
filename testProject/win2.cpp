
#include "win2.h"

win2::win2() : Window(30, 30, 5, 5) {
    label1 = new TextBlock(1, 1, 13, A_NORMAL, "v1: 10");
    addControl(label1);
    label2 = new TextBlock(15, 1, 13, A_NORMAL, "v2: 10");
    addControl(label2);
    slider1 = new Slider(2, 20, 2, 10, 13, 1, 3, A_NORMAL, A_STANDOUT, A_NORMAL | COLOR_PAIR(1),
                         A_STANDOUT | COLOR_PAIR(1), true, true);
    addControl(slider1);
    slider2 = new Slider(6, 24, 2, 10, 13, 15, 3, A_NORMAL, A_STANDOUT, A_NORMAL | COLOR_PAIR(1),
                         A_STANDOUT | COLOR_PAIR(1), true, true);
    addControl(slider2);
}

WindowProcessResult win2::processInput(int input) {
    label1->setText("v1: " + std::to_string(slider1->getValue()));
    label2->setText("v2: " + std::to_string(slider2->getValue()));
    return Window::processInput(input);
}
