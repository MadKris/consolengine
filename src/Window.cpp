#include <algorithm>
#include "../include/Window.h"

Window::Window(int width, int height, int x, int y) :
        pWindow(newwin(height, width, y, x)), focusedIndex(0), focusedControl(nullptr), needsRedraw(false) {
    windowAttributes = A_NORMAL;
}


void Window::addControl(Control *c) {
    if(std::find(controls.begin(), controls.end(), c) == controls.end())
    {
        return;
    }
    controls.push_back(c);
}
void Window::removeControl(Control *c) {
    auto found = std::find(controls.begin(), controls.end(), c);
    if(found == controls.end())
    {
        return;
    }
    controls.erase(found);
}


void Window::renderWindow() {
    renderWindowBase();
    for(auto &control : controls)
    {
        wattrset(pWindow, windowAttributes);
        control->renderControl(pWindow, control == focusedControl);
    }
    needsRedraw = false;
    wrefresh(pWindow);
}

void Window::renderWindowBase() const {
    wattrset(pWindow, windowAttributes);
    wbkgd(pWindow, COLOR_BLACK);
    box(pWindow, 0, 0);
}


WindowProcessResult Window::processInput(int input) {
    return WindowProcessResult(0, nullptr);
}

void Window::focusPrev() {
    focusedIndex--;
    if(focusedIndex < 0)
    {
        focusedIndex = controls.size() - 1;
    }
    syncFocus();
}

void Window::syncFocus() {
    if(controls.empty()) {
        return;
    }
    focusedControl = controls.at(focusedIndex);
}

void Window::focusNext() {
    focusedIndex++;
    if(focusedIndex >= controls.size())
    {
        focusedIndex = 0;
    }
    syncFocus();
}

Window::~Window() {
    for(auto &control : controls)
    {
        delete control;
    }
    delwin(pWindow);
}

void Window::setRedrawFlag() {
    needsRedraw = true;
}

