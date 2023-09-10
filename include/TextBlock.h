
#ifndef CONSOLE_INTERACTIVE_ENGINE_TEXTBLOCK_H
#define CONSOLE_INTERACTIVE_ENGINE_TEXTBLOCK_H


#include <string>
#include "Control.h"

class TextBlock : public Control {
protected:
    int x;
    int y;
    int width;
    int textAttributes;
    std::string text;
public:
    TextBlock(int x, int y, int width, int textAttributes, const std::string &text = "");

    [[nodiscard]] int getX() const;

    [[nodiscard]] int getTextAttributes() const;

    void setTextAttributes(int textAttributes);

    void setX(int x);

    [[nodiscard]] int getY() const;

    void setY(int y);

    [[nodiscard]] int getWidth() const;

    void setWidth(int width);

    void setText(const std::string &newText);

    [[nodiscard]] const std::string &getText() const;

    void renderControl(WINDOW *window, bool focused) override;
};


#endif //CONSOLE_INTERACTIVE_ENGINE_TEXTBLOCK_H
