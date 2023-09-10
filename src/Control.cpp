
#include "../include/Control.h"

Control::~Control() = default;

bool Control::isVisible() const {
    return visible;
}

void Control::setVisible(bool visible) {
    this->visible = visible;
}
