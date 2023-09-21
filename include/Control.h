
#ifndef CONSOLE_INTERACTIVE_ENGINE_CONTROL_H
#define CONSOLE_INTERACTIVE_ENGINE_CONTROL_H


#include <ncurses.h>
#include <vector>
#include <functional>
#include "UIObject.h"

typedef void (handlerType)();

typedef std::function<handlerType> handler;

class Control : public UIObject {
public:
    virtual void addActionHandler(handler function);
    virtual void removeActionHandler(handler function);
    virtual void action();
    bool isVisible() const;
    void setVisible(bool visible);
    virtual ~Control();
protected:
    bool visible;
    std::vector<handler> actionHandlers;
};


#endif //CONSOLE_INTERACTIVE_ENGINE_CONTROL_H
