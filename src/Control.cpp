
#include "../include/Control.h"

Control::~Control() = default;

bool Control::isVisible() const {
    return visible;
}

void Control::setVisible(bool visible) {
    this->visible = visible;
}

void Control::action() {
    for(const auto& func : actionHandlers)
    {
        func();
    }
}

void Control::addActionHandler(handler function) {
    actionHandlers.push_back(function);
}

void Control::removeActionHandler(handler function) {
    actionHandlers.erase(std::find_if(actionHandlers.begin(), actionHandlers.end(),
                                      [=](auto &a){
        return  function.target<handlerType>() == a.template target<handlerType>();
    }));
}
