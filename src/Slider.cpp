
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
          printLabels(printLabels) {
    if (step <= 0) {
        throw std::invalid_argument("Slider::step");
    }
    if (maxValue <= minValue || (maxValue - minValue) % step > 0) {
        throw std::invalid_argument("Slider::maxValue");
    }
    if (value - minValue < 0 || (value - minValue) % step > 0) {
        throw std::invalid_argument("Slider::value");
    }
}

void Slider::render(WINDOW *window, bool focused) {
    if (printLabels) {
        wattron(window, defaultAttributes);
        mvwprintw(window, y + 1, x, "%-*d%*d", size / 2, minValue, size - size / 2, maxValue);
    }
    wattron(window, focused ? focusedAttributes : defaultAttributes);
    int sliderFill = ((float) (value - maxValue) / (maxValue - minValue)) * (size - 2);
    mvwprintw(window, y, x, "[%s%*s]", std::string(sliderFill, '|').c_str(), size - 2 - sliderFill, "");
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

