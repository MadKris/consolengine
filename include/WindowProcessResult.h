
#ifndef CONSOLEINTERACTIVEENGINE_WINDOWPROCESSRESULT_H
#define CONSOLEINTERACTIVEENGINE_WINDOWPROCESSRESULT_H

enum WindowProcessResultStatus {
    WINDOW_STATUS_OK,
    WINDOW_STATUS_CLOSE,
    WINDOW_STATUS_OPEN_NEW
};

struct WindowProcessResult {
    explicit WindowProcessResult(WindowProcessResultStatus status, void *arg = nullptr) : statusCode(status), arg(arg) {}
    WindowProcessResultStatus statusCode;
    void *arg;
};



#endif //CONSOLEINTERACTIVEENGINE_WINDOWPROCESSRESULT_H
