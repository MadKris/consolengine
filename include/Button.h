
#ifndef CONSOLE_INTERACTIVE_ENGINE_BUTTON_H
#define CONSOLE_INTERACTIVE_ENGINE_BUTTON_H


#include <string>
#include "Control.h"
class Button : public Control {
protected:
public:
    [[nodiscard]] const std::string &getText() const;

    void setText(const std::string &text);

    [[nodiscard]] int getX() const;

    void setX(int x);

    [[nodiscard]] int getY() const;

    void setY(int y);

    [[nodiscard]] int getWidth() const;

    void setWidth(int width);

    [[nodiscard]] int getTextAttributes() const;

    void setTextAttributes(int textAttributes);

    [[nodiscard]] int getFocusedTextAttributes() const;

    void setFocusedTextAttributes(int focusedTextAttributes);

    Button(int x, int y, int width, int textAttributes, int focusedTextAttributes, const std::string &text);
    Button(int x, int y, int textAttributes, int focusedTextAttributes, const std::string &text);

    void render(WINDOW *window, bool focused) override;

protected:
    std::string text;
    int x;
    int y;
    int width;
    int textAttributes;
    int focusedTextAttributes;
};


#endif //CONSOLE_INTERACTIVE_ENGINE_BUTTON_H
