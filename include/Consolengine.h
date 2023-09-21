
#ifndef CONSOLE_INTERACTIVE_ENGINE_CONSOLENGINE_H
#define CONSOLE_INTERACTIVE_ENGINE_CONSOLENGINE_H


#include <stack>
#include "Window.h"

class Consolengine {
public:
    Consolengine(Window *rootWindow);
    virtual int run();
    ~Consolengine();
protected:
    Consolengine() : mStoppingFlag(false) {
    }
    virtual int handleInput();
    virtual void processLogic(int input);
    virtual void renderScreen();
    virtual int runGameLoop();
private:
    bool mStoppingFlag;
    std::stack<Window *> mWindowStack;
    void openWindow(Window *window);
};


#endif //CONSOLE_INTERACTIVE_ENGINE_CONSOLENGINE_H