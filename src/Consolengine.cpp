
#include <exception>
#include <iostream>
#include <thread>

#include "../include/Consolengine.h"



int Consolengine::run() {
    return runGameLoop();
}

int Consolengine::runGameLoop() {
    try {
        using namespace std::chrono_literals;
        while (!this->mStoppingFlag) {
            renderScreen();
            int input = handleInput();
            processLogic(input);
            std::this_thread::sleep_for(2ms); // Give CPU to other apps, ~500 fps is fast enough
        }
    }
    catch (std::exception &e)
    {
        std::cerr << " [Game Loop] : Exception: " << e.what();
        return -1;
    }
    return 0;
}

int Consolengine::handleInput() {
    return wgetch(mWindowStack.top()->pWindow);
}

void Consolengine::processLogic(int input) {
    auto result = mWindowStack.top()->processInput(input);
    switch (result.statusCode) {

        case WINDOW_STATUS_OK:
            return;
        case WINDOW_STATUS_CLOSE:
            clear();
            refresh();
            delete mWindowStack.top();
            mWindowStack.pop();
            mStoppingFlag = mWindowStack.empty(); // if WindowStack is empty - stopping the main loop. Nothing to render!
            break;
        case WINDOW_STATUS_OPEN_NEW:
            auto window = reinterpret_cast<Window *>(result.arg);
            if(window == nullptr)
            {
                throw std::invalid_argument("Invalid argument: Window * expected");
            }
            openWindow(window);
            break;
    }
}

void Consolengine::openWindow(Window *window) {
    nodelay(window->pWindow, TRUE);
    keypad(window->pWindow, TRUE);
    mWindowStack.push(window);
}

void Consolengine::renderScreen() {
    mWindowStack.top()->render(nullptr, false);
}

Consolengine::Consolengine(Window *rootWindow) : mStoppingFlag(false) {
    openWindow(rootWindow);
}

Consolengine::~Consolengine() {
    while(!mWindowStack.empty())
    {
        delete mWindowStack.top();
        mWindowStack.pop();
    }
}
