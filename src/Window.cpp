#include <algorithm>
#include "../include/Window.h"
#include "../include/UIObject.h"

Window::Window(int width, int height, int x, int y) : pWindow(newwin(height, width, y, x)), focusedIndex(0),
                                                      focusedControl(nullptr), needsRedraw(false), closing(false) {
    windowAttributes = A_NORMAL;
}


void Window::addControl(Control *c) {
    if (std::find(controls.begin(), controls.end(), c) != controls.end()) {
        return;
    }
    controls.push_back(c);
    // Some weird code that will reset focus to focusable element
    focusNext();
    focusPrev();
}

void Window::removeControl(Control *c) {
    auto found = std::find(controls.begin(), controls.end(), c);
    if (found == controls.end()) {
        return;
    }
    controls.erase(found);
}


void Window::render(WINDOW *win, bool focused) {
    renderWindowBase();
    for (auto &control: controls) {
        wattrset(pWindow, windowAttributes);
        control->render(pWindow, control == focusedControl);
    }
    needsRedraw = false;
    wrefresh(pWindow);
}

void Window::renderWindowBase() const {
    wattrset(pWindow, windowAttributes);
    if (needsRedraw) {
        werase(pWindow);
    }
    box(pWindow, 0, 0);
    wrefresh(pWindow);
}


WindowProcessResult Window::processInput(int input) {
    if (focusedControl != nullptr) {
        focusedControl->processInput(input);
    }
    switch (input) {
        case KEY_UP:
            focusPrev();
            break;
        case KEY_DOWN:
            focusNext();
            break;
    }
    if (this->closing) {
        return WindowProcessResult(WINDOW_STATUS_CLOSE, nullptr);
    }
    return WindowProcessResult(WINDOW_STATUS_OK, nullptr);
}

void Window::focusPrev() {
    if (controls.empty()) {
        return;
    }
    int initialFocus = focusedIndex;
    do {
        focusedIndex--;
        if (focusedIndex < 0) {
            focusedIndex = controls.size() - 1;
        }
        syncFocus();
    } while (focusedIndex != initialFocus && !focusedControl->isFocusable());
}

void Window::syncFocus() {
    if (controls.empty()) {
        return;
    }
    focusedControl = controls.at(focusedIndex);
}

void Window::focusNext() {
    if (controls.empty()) {
        return;
    }
    int initialFocus = focusedIndex;
    do {
        focusedIndex++;
        if (focusedIndex >= controls.size()) {
            focusedIndex = 0;
        }
        syncFocus();
    } while (initialFocus != focusedIndex && !focusedControl->isFocusable());
}

Window::~Window() {
    for (auto &control: controls) {
        delete control;
    }
    delwin(pWindow);
}

void Window::setRedrawFlag() {
    needsRedraw = true;
}

void Window::close() {
    closing = true;
}

int Window::getHorizontalCenter() {
    return getmaxx(pWindow) / 2;
}

int Window::getVerticalCenter() {
    return getmaxy(pWindow) / 2;
}
