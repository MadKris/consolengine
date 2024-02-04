cmake_minimum_required(VERSION 3.25)

project(ConsoleInteractiveEngine VERSION 0.3)


set(CMAKE_CXX_STANDARD 20)

add_library(consolengine SHARED
        src/Consolengine.cpp
        include/Consolengine.h
        src/Window.cpp
        include/Window.h
        src/Button.cpp
        include/Button.h
        src/Slider.cpp
        include/Slider.h
        src/ToggleGroup.cpp
        include/ToggleGroup.h
        src/Control.cpp
        include/Control.h
        src/TextBlock.cpp
        include/TextBlock.h
        src/UIObject.cpp
        include/UIObject.h
        include/WindowProcessResult.h
)
target_link_libraries(consolengine PUBLIC ncurses)

install (TARGETS consolengine DESTINATION lib)
install(FILES 
        include/Control.h
        include/TextBlock.h
        include/ToggleGroup.h
        include/Window.h
        include/Slider.h
        include/Consolengine.h
        include/Button.h
        include/UIObject.h
        include/WindowProcessResult.h
        DESTINATION include/consolengine)
