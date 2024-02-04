#include "../include/Toggle.h"

Toggle::Toggle(int x, int y, int width, const std::string &label, int toggleIconDefaultAttributes,
               int toggleIconFocusedAttributes,
               int labelDefaultAttributes, int labelFocusedAttributes, bool toggled,
               bool visible) : Control(visible, true), x(x), y(y),
                               toggleIconDefaultAttributes(toggleIconDefaultAttributes),
                               toggleIconFocusedAttributes(toggleIconFocusedAttributes),
                               labelDefaultAttributes(labelDefaultAttributes),
                               labelFocusedAttributes(labelFocusedAttributes),
                               width(width), toggled(toggled),
                               label(label) {
    actionHandlers.emplace_back([this]() { this->toggled = !this->toggled; });
}

Toggle::Toggle(int x, int y, const std::string &label, int toggleIconDefaultAttributes, int toggleIconFocusedAttributes,
               int labelDefaultAttributes, int labelFocusedAttributes, bool toggled,
               bool visible) : Toggle(x, y, label.size(), label, toggleIconDefaultAttributes,
                                      toggleIconFocusedAttributes,
                                      labelDefaultAttributes, labelFocusedAttributes, toggled, visible) {
}

Toggle::Toggle(int x, int y, int width, const std::string &label, int defaultAttributes,
               int toggleIconFocusedAttributes,
               int labelFocusedAttributes, bool toggled,
               bool visible) : Toggle(x, y, width, label, defaultAttributes, toggleIconFocusedAttributes,
                                      defaultAttributes,
                                      labelFocusedAttributes, toggled, visible) {
}

Toggle::Toggle(int x, int y, const std::string &label, int defaultAttributes, int toggleIconFocusedAttributes,
               int labelFocusedAttributes, bool toggled, bool visible) : Toggle(x, y,
                                                                                label,
                                                                                defaultAttributes,
                                                                                toggleIconFocusedAttributes,
                                                                                defaultAttributes,
                                                                                labelFocusedAttributes,
                                                                                toggled,
                                                                                visible) {
}

void Toggle::action() {
    Control::action();
}

void Toggle::render(WINDOW *window, bool focused) {
    if (!this->visible) {
        return;
    }

    wattron(window, focused ? labelFocusedAttributes : labelDefaultAttributes);
    mvwprintw(window, y, x, "[ ] %.*s", width, label.c_str());
    wattron(window, focused ? toggleIconFocusedAttributes : toggleIconDefaultAttributes);
    mvwprintw(window, y, x + 1, "%c", (toggled ? '*' : ' '));
}

void Toggle::processInput(int input) {
    switch (input) {
        case ' ':
            action();
            break;
    }
    Control::processInput(input);
}

bool Toggle::isToggled() const {
    return toggled;
}

void Toggle::setToggled(bool toggled) {
    Toggle::toggled = toggled;
}

int Toggle::getX() const {
    return x;
}

void Toggle::setX(int x) {
    Toggle::x = x;
}

int Toggle::getY() const {
    return y;
}

void Toggle::setY(int y) {
    Toggle::y = y;
}

int Toggle::getToggleIconFocusedAttributes() const {
    return toggleIconFocusedAttributes;
}

void Toggle::setToggleIconFocusedAttributes(int toggleIconFocusedAttributes) {
    Toggle::toggleIconFocusedAttributes = toggleIconFocusedAttributes;
}

int Toggle::getToggleIconDefaultAttributes() const {
    return toggleIconDefaultAttributes;
}

void Toggle::setToggleIconDefaultAttributes(int toggleIconDefaultAttributes) {
    Toggle::toggleIconDefaultAttributes = toggleIconDefaultAttributes;
}

int Toggle::getLabelDefaultAttributes() const {
    return labelDefaultAttributes;
}

void Toggle::setLabelDefaultAttributes(int labelDefaultAttributes) {
    Toggle::labelDefaultAttributes = labelDefaultAttributes;
}

int Toggle::getLabelFocusedAttributes() const {
    return labelFocusedAttributes;
}

void Toggle::setLabelFocusedAttributes(int labelFocusedAttributes) {
    Toggle::labelFocusedAttributes = labelFocusedAttributes;
}

int Toggle::getWidth() const {
    return width;
}

void Toggle::setWidth(int width) {
    Toggle::width = width;
}

const std::string &Toggle::getLabel() const {
    return label;
}

void Toggle::setLabel(const std::string &label) {
    Toggle::label = label;
}

Toggle::~Toggle() = default;
