
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
    bool printingLabels;
public:
    void render(WINDOW *window, bool focused) override;

    void processInput(int input) override;

    void incrementValue();

    void decrementValue();

    [[nodiscard]] int getValue() const;

    void setValue(int value);

    [[nodiscard]] int getMinValue() const;

    [[nodiscard]] int getMaxValue() const;

    [[nodiscard]] int getStep() const;

    void updateBounds(int minValue, int maxValue, int step, int value);

    [[nodiscard]] int getSize() const;

    void setSize(int size);

    [[nodiscard]] int getX() const;

    void setX(int x);

    [[nodiscard]] int getY() const;

    void setY(int y);

    [[nodiscard]] int getDefaultAttributes() const;

    void setDefaultAttributes(int defaultAttributes);

    [[nodiscard]] int getFocusedAttributes() const;

    void setFocusedAttributes(int focusedAttributes);

    [[nodiscard]] int getDefaultHandleAttributes() const;

    void setDefaultHandleAttributes(int defaultHandleAttributes);

    [[nodiscard]] int getFocusedHandleAttributes() const;

    void setFocusedHandleAttributes(int focusedHandleAttributes);

    [[nodiscard]] bool isPrintingLabels() const;

    void setPrintingLabels(bool printingLabels);

    static void checkBounds(int minValue, int maxValue, int step, int value);
};


#endif //CONSOLE_INTERACTIVE_ENGINE_SLIDER_H
