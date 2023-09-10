
#ifndef CONSOLE_INTERACTIVE_ENGINE_CONTROL_H
#define CONSOLE_INTERACTIVE_ENGINE_CONTROL_H


#include <ncurses.h>

class Control {
public:
    virtual void renderControl(WINDOW *window, bool focused) = 0;
    virtual ~Control();
protected:
    bool visible;
public:
    bool isVisible() const;

    void setVisible(bool visible);
};


#endif //CONSOLE_INTERACTIVE_ENGINE_CONTROL_H
