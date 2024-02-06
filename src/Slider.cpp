
#include <cassert>
#include <stdexcept>
#include "../include/Slider.h"

Slider::Slider(int minValue, int maxValue, int step, int value, int size, int x, int y, int defaultAttributes,
               int focusedAttributes, int defaultHandleAttributes, int focusedHandleAttributes, bool printLabels,
               bool visible)
        : Control(visible, true),
          value(value),
          minValue(minValue),
          maxValue(maxValue),
          step(step),
          size(size), x(x),
          y(y),
          defaultAttributes(defaultAttributes),
          focusedAttributes(focusedAttributes),
          defaultHandleAttributes(defaultHandleAttributes),
          focusedHandleAttributes(focusedHandleAttributes),
          printingLabels(printLabels) {
    checkBounds(minValue, maxValue, step, value);
}

void Slider::checkBounds(int minValue, int maxValue, int step, int value) {
    if (step <= 0) {
        throw std::invalid_argument("Slider::step");
    }
    if (maxValue <= minValue || (maxValue - minValue) % step > 0) {
        throw std::invalid_argument("Slider::maxValue");
    }
    if (value < minValue || value > maxValue || (value - minValue) % step > 0) {
        throw std::invalid_argument("Slider::value");
    }
}

void Slider::render(WINDOW *window, bool focused) {
    if (printingLabels) {
        wattron(window, defaultAttributes);
        mvwprintw(window, y + 1, x, "%-*d%*d", size / 2, minValue, size - size / 2, maxValue);
    }
    wattron(window, focused ? focusedAttributes : defaultAttributes);
    int sliderFill = ((float) (value - maxValue) / (maxValue - minValue)) * (size - 2);
    mvwprintw(window, y, x, "[%s%*s]", std::string(sliderFill, '|').c_str(), size - 2 - sliderFill, "");

    wattron(window, focused ? focusedHandleAttributes : defaultHandleAttributes);
    mvwprintw(window, y, x + 1 + sliderFill, "O");
}

void Slider::incrementValue() {
    if (value < maxValue) {
        value += step;
    }
}

void Slider::decrementValue() {
    if (value > minValue) {
        value -= step;
    }
}

void Slider::processInput(int input) {
    switch (input) {
        case KEY_RIGHT:
            incrementValue();
            break;
        case KEY_LEFT:
            decrementValue();
            break;
        default:
            Control::processInput(input);
            break;
    }
}

int Slider::getValue() const {
    return value;
}

void Slider::setValue(int value) {
    if (value < minValue || value > maxValue || (value - minValue) % step > 0) {
        throw std::invalid_argument("Slider::value");
    }
    Slider::value = value;
}

int Slider::getMinValue() const {
    return minValue;
}

int Slider::getMaxValue() const {
    return maxValue;
}

int Slider::getStep() const {
    return step;
}

int Slider::getSize() const {
    return size;
}

int Slider::getX() const {
    return x;
}

void Slider::setX(int x) {
    Slider::x = x;
}

int Slider::getY() const {
    return y;
}

void Slider::setY(int y) {
    Slider::y = y;
}

int Slider::getDefaultAttributes() const {
    return defaultAttributes;
}

void Slider::setDefaultAttributes(int defaultAttributes) {
    Slider::defaultAttributes = defaultAttributes;
}

int Slider::getFocusedAttributes() const {
    return focusedAttributes;
}

void Slider::setFocusedAttributes(int focusedAttributes) {
    Slider::focusedAttributes = focusedAttributes;
}

int Slider::getDefaultHandleAttributes() const {
    return defaultHandleAttributes;
}

void Slider::setDefaultHandleAttributes(int defaultHandleAttributes) {
    Slider::defaultHandleAttributes = defaultHandleAttributes;
}

int Slider::getFocusedHandleAttributes() const {
    return focusedHandleAttributes;
}

void Slider::setFocusedHandleAttributes(int focusedHandleAttributes) {
    Slider::focusedHandleAttributes = focusedHandleAttributes;
}

bool Slider::isPrintingLabels() const {
    return printingLabels;
}

void Slider::setPrintingLabels(bool printingLabels) {
    Slider::printingLabels = printingLabels;
}

void Slider::setSize(int size) {
    Slider::size = size;
}

void Slider::updateBounds(int minValue, int maxValue, int step, int value) {
    checkBounds(minValue, maxValue, step, value);
    Slider::minValue = minValue;
    Slider::maxValue = maxValue;
    Slider::step = step;
    Slider::value = value;
}

