cmake_minimum_required(VERSION 3.25)

project(ConsoleInteractiveEngineTestProject VERSION 0.3)

set(CMAKE_CXX_STANDARD 20)

add_executable(consoleWindowTest main.cpp win1.h win1.cpp
        win2.cpp
        win2.h)

target_link_libraries(consoleWindowTest ncurses)
target_link_libraries(consoleWindowTest consolengine)