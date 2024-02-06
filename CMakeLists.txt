cmake_minimum_required(VERSION 3.25)

project(ConsoleInteractiveEngine VERSION 0.4)


set(CMAKE_CXX_STANDARD 20)
if (NOT CMAKE_BUILD_TYPE MATCHES DEBUG)
    add_definitions(-DNDEBUG)
endif ()

add_library(consolengine SHARED
        src/Consolengine.cpp
        include/Consolengine.h
        src/Window.cpp
        include/Window.h
        src/Button.cpp
        include/Button.h
        src/Slider.cpp
        include/Slider.h
        src/Toggle.cpp
        include/Toggle.h
        src/Control.cpp
        include/Control.h
        src/TextBlock.cpp
        include/TextBlock.h
        src/UIObject.cpp
        include/UIObject.h
        include/WindowProcessResult.h
)
target_link_libraries(consolengine PUBLIC ncurses)

add_subdirectory(testProject)

install(TARGETS consolengine DESTINATION lib)
install(FILES
        include/Control.h
        include/TextBlock.h
        include/Window.h
        include/Slider.h
        include/Consolengine.h
        include/Toggle.h
        include/Button.h
        include/UIObject.h
        include/WindowProcessResult.h
        DESTINATION include/consolengine)

set(CPACK_PACKAGE_NAME consolengine)
set(CPACK_PACKAGE_CONTACT "MadKris <mkris.yt@gmail.com>")
set(CPACK_GENERATOR DEB)
include(CPack)
