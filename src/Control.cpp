#include "../include/Control.h"

Control::~Control() = default;

bool Control::isVisible() const {
    return visible;
}

void Control::setVisible(bool visible) {
    this->visible = visible;
}

void Control::action() {
    for (const auto &func: actionHandlers) {
        func();
    }
}

void Control::processInput(int input) {
    switch (input) {
        case KEY_ENTER:
        case '\n':
        case '\r':
            this->action();
            break;
    }
}

void Control::addActionHandler(handler function) {
    actionHandlers.push_back(function);
}

void Control::removeActionHandler(handler function) {
    actionHandlers.erase(std::find_if(actionHandlers.begin(), actionHandlers.end(),
                                      [=](auto &a) {
                                          return function.target<handlerType>() == a.template target<handlerType>();
                                      }));
}

Control::Control(bool visible, bool focusable) : visible(visible), focusable(focusable) {
}

bool Control::isFocusable() const {
    return focusable;
}

void Control::setFocusable(bool focusable) {
    this->focusable = focusable;
}
