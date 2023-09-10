
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
public:
    int getTextAttributes() const;

    void setTextAttributes(int textAttributes);

protected:
    std::string text;
public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getWidth() const;

    void setWidth(int width);

    TextBlock(int x, int y, int width, int textAttributes, const std::string &text = "");

    void setText(const std::string &newText);
    [[nodiscard]] const std::string &getText() const;
    void renderControl(WINDOW *window, bool focused) override;
};


#endif //CONSOLE_INTERACTIVE_ENGINE_TEXTBLOCK_H
