#include "win1.h"
#include "win2.h"

win1::win1() : Window(30, 15, 2, 2), openWin2(false) {

    _title = new TextBlock(1, 1, getmaxx(Window::pWindow) - 1, A_STANDOUT | A_BOLD | A_UNDERLINE, "Hello, world");
    addControl(_title);
    _win2Btn = new Button(1, 3, A_NORMAL, A_BOLD | A_UNDERLINE, "window 2");
    _win2Btn->addActionHandler([this]() { this->openWin2 = true; });
    addControl(_win2Btn);
    _quitBtn = new Button(1, 5, A_NORMAL, A_BOLD | A_UNDERLINE, "quit");
    _quitBtn->addActionHandler([this]() { this->close(); });
    addControl(_quitBtn);

    _toggle1 = new Toggle(1, 7, "Custom len toggle", A_NORMAL, A_BOLD | COLOR_PAIR(1),
                          A_STANDOUT | A_BOLD | A_UNDERLINE);
    addControl(_toggle1);
    _toggle2 = new Toggle(1, 9, 12, "This doesn't fit", A_BOLD, A_BOLD | COLOR_PAIR(1), A_ITALIC,
                          A_ITALIC | A_UNDERLINE, false, true);
    addControl(_toggle2);
}

WindowProcessResult win1::processInput(int input) {
    if (openWin2) {
        openWin2 = false;
        return WindowProcessResult(WINDOW_STATUS_OPEN_NEW, new win2());
    }
    switch (input) {
        case KEY_F(10):
            return WindowProcessResult(WINDOW_STATUS_CLOSE, nullptr);
        default:
            return Window::processInput(input);
    }
}
