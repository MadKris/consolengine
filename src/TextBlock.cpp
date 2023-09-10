
#include "../include/TextBlock.h"

void TextBlock::renderControl(WINDOW *window, bool focused) {
    if(this->visible) {
        return;
    }
    wattron(window, this->textAttributes);
    for(int i = 0, line = 0; i < this->text.size(); i += width, line++) {
        mvwprintw(window, y + line, x, "%.*s\n", this->width, this->text.c_str()+i);
    }
}


const std::string &TextBlock::getText() const {
    return this->text;
}

void TextBlock::setText(const std::string &newText) {
    this->text = newText;
}

TextBlock::TextBlock(int x, int y, int width, int textAttributes, const std::string &text)
        : x(x), y(y), width(width), textAttributes(textAttributes), text(text) {}

int TextBlock::getX() const {
    return x;
}

void TextBlock::setX(int x) {
    this->x = x;
}

int TextBlock::getY() const {
    return y;
}

void TextBlock::setY(int y) {
    this->y = y;
}

int TextBlock::getWidth() const {
    return width;
}

void TextBlock::setWidth(int width) {
    this->width = width;
}

int TextBlock::getTextAttributes() const {
    return textAttributes;
}

void TextBlock::setTextAttributes(int textAttributes) {
    this->textAttributes = textAttributes;
}
