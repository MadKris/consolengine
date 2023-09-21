
#include "../include/Button.h"

void Button::render(WINDOW *window, bool focused) {
    if(!this->visible) {
        return;
    }
    if(focused) {
        wattron(window, this->focusedTextAttributes);
    }
    else {
        wattron(window, this->textAttributes);
    }
    mvwprintw(window, y, x, focused ? "[ %.*s ]" : "< %.*s >", this->width + 4, this->text.c_str());
}

Button::Button(int x, int y, int width, int textAttributes, int focusedTextAttributes, const std::string &text) : x(x), y(y),
                                                                                                            width(width),
                                                                                                            textAttributes(textAttributes),
                                                                                                            text(text),
                                                                                                            focusedTextAttributes(
                                                                                                                    focusedTextAttributes) {}
Button::Button(int x, int y, int textAttributes, int focusedTextAttributes, const std::string &text) : x(x), y(y),
                                                                                                                  width(text.length()),
                                                                                                                  textAttributes(textAttributes),
                                                                                                                  text(text),
                                                                                                                  focusedTextAttributes(
                                                                                                                          focusedTextAttributes) {}

const std::string &Button::getText() const {
    return text;
}

void Button::setText(const std::string &text) {
    Button::text = text;
}

int Button::getX() const {
    return x;
}

void Button::setX(int x) {
    Button::x = x;
}

int Button::getY() const {
    return y;
}

void Button::setY(int y) {
    Button::y = y;
}

int Button::getWidth() const {
    return width;
}

void Button::setWidth(int width) {
    Button::width = width;
}

int Button::getTextAttributes() const {
    return textAttributes;
}

void Button::setTextAttributes(int textAttributes) {
    Button::textAttributes = textAttributes;
}

int Button::getFocusedTextAttributes() const {
    return focusedTextAttributes;
}

void Button::setFocusedTextAttributes(int focusedTextAttributes) {
    Button::focusedTextAttributes = focusedTextAttributes;
}
