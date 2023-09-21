
#ifndef CONSOLEINTERACTIVEENGINE_UIOBJECT_H
#define CONSOLEINTERACTIVEENGINE_UIOBJECT_H


#include <functional>
#include <vector>
#include <ncurses.h>

class UIObject {

public:
    virtual void render(WINDOW *window, bool focused) = 0;
};


#endif //CONSOLEINTERACTIVEENGINE_UIOBJECT_H
