#ifndef CONSOLE_INTERACTIVE_ENGINE_TOGGLE_H
#define CONSOLE_INTERACTIVE_ENGINE_TOGGLE_H

#include "Control.h"
#include <string>

class Toggle : public Control {
public:
    Toggle(int x, int y, int width, const std::string &label, int toggleIconDefaultAttributes,
           int toggleIconFocusedAttributes, int labelDefaultAttributes, int labelFocusedAttributes,
           bool toggled = false,
           bool visible = true);

    Toggle(int x, int y, const std::string &label, int toggleIconDefaultAttributes, int toggleIconFocusedAttributes,
           int labelDefaultAttributes, int labelFocusedAttributes, bool toggled = false, bool visible = true);

    Toggle(int x, int y, int width, const std::string &label, int defaultAttributes,
           int toggleIconFocusedAttributes,
           int labelFocusedAttributes, bool toggled, bool visible);

    Toggle(int x, int y, const std::string &label, int defaultAttributes, int toggleIconFocusedAttributes,
           int labelFocusedAttributes, bool toggled = false, bool visible = true);

    void action() override;

    void render(WINDOW *window, bool focused) override;

    void processInput(int input) override;

    [[nodiscard]] bool isToggled() const;

    void setToggled(bool toggled);

    [[nodiscard]] int getX() const;

    void setX(int x);

    [[nodiscard]] int getY() const;

    void setY(int y);

    [[nodiscard]] int getToggleIconFocusedAttributes() const;

    void setToggleIconFocusedAttributes(int toggleIconFocusedAttributes);

    [[nodiscard]] int getToggleIconDefaultAttributes() const;

    void setToggleIconDefaultAttributes(int toggleIconDefaultAttributes);

    [[nodiscard]] int getLabelDefaultAttributes() const;

    void setLabelDefaultAttributes(int labelDefaultAttributes);

    [[nodiscard]] int getLabelFocusedAttributes() const;

    void setLabelFocusedAttributes(int labelFocusedAttributes);

    [[nodiscard]] int getWidth() const;

    void setWidth(int width);

    [[nodiscard]] const std::string &getLabel() const;

    void setLabel(const std::string &label);

    ~Toggle() override;

protected:
    bool toggled;
    int x;
    int y;
    int toggleIconFocusedAttributes;
    int toggleIconDefaultAttributes;
    int labelDefaultAttributes;
    int labelFocusedAttributes;
    int width;
    std::string label;
};

#endif  // CONSOLE_INTERACTIVE_ENGINE_TOGGLE_H
