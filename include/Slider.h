
#ifndef CONSOLE_INTERACTIVE_ENGINE_SLIDER_H
#define CONSOLE_INTERACTIVE_ENGINE_SLIDER_H


#include "Control.h"

class Slider : public Control {
public:
    Slider(int minValue, int maxValue, int step, int value, int size, int x, int y, int defaultAttributes,
           int focusedAttributes, int defaultHandleAttributes, int focusedHandleAttributes, bool printLabels = false,
           bool visible = true);

protected:
    int value;
    int minValue;
    int maxValue;
    int step;
    int size;
    int x;
    int y;
    int defaultAttributes;
    int focusedAttributes;
    int defaultHandleAttributes;
    int focusedHandleAttributes;
    bool printLabels;
public:
    void render(WINDOW *window, bool focused) override;

    void processInput(int input) override;

    void incrementValue();

    void decrementValue();
};


#endif //CONSOLE_INTERACTIVE_ENGINE_SLIDER_H
