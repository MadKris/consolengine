
#ifndef CONSOLE_INTERACTIVE_ENGINE_WINDOW_H
#define CONSOLE_INTERACTIVE_ENGINE_WINDOW_H


#include <vector>
#include <ncurses.h>
#include "Control.h"

#define ctrl(x) ((x) & 0x1f)

struct WindowProcessResult {
    int statusCode;
    void *arg;
};

class Window : public UIObject {
protected:
    std::vector<Control *> controls;
    Control *focusedControl{};
    int32_t focusedIndex;
    WINDOW *pWindow;
    int windowAttributes;
    bool needsRedraw;
    bool closing;
    // We're adding raw pointer to Control instance here.
    // Once this method is called it is this class's responsibility to free given control. No need to free it manually
    virtual void addControl(Control *c);
    // Removes control from array and releases the memory
    virtual void removeControl(Control *c);
    virtual void renderWindowBase() const;
    virtual void focusNext();
    virtual void focusPrev();
    virtual void setRedrawFlag();
    virtual void close();
public:
    Window(int width, int height, int x, int y);
    virtual WindowProcessResult processInput(int input);
    void render(WINDOW *win, bool focused) override;
    virtual ~Window();

    int getHorizontalCenter();
    int getVerticalCenter();

    friend class Consolengine;
    void syncFocus();
};


#endif //CONSOLE_INTERACTIVE_ENGINE_WINDOW_H
