# CONSOLENGINE

This project makes it easier to make multi-window interactive console apps with ncurses library. It gives an extra level
of abstraction so you don't just print stuff on window but create windows and controls.

This library handles these functions:

* provides `Window` class that encapsulates ncurses `WINDOW*` object, handles re-rendering of that window and acts as
  a `Control` container,
* provides `Control` class and it's inherited classes to populate the `Window`
* handles window rendering loop at 500 FPS (2 ms between renders)
* handles input and simplifies processing of it
* handles a window stack. Current window is on top of stack and is popped from it when it asks so. If stack is empty the
  engine stops.

This library does not cover other parts of ncurses, including initialization. You still have to do it yourself. Library
still heavily depends on raw ncurses code. It uses ncurses text attributes for formatting and it is on you to manage.
Any further customizations to render through overriding render functions also require using raw ncurses code.

## Installation:

I never tested this library on non-linux systems but theoretically it should work as long as you have an NCURSES
implementation installed in your system. Linux is more likely to work, of course.

I am not distributing binaries at the moment so you have to build it yourself.

Create a build dir in project and change to it:

    mkdir build && cd build

Configure cmake:

    cmake .. -DCMAKE_BUILD_TYPE=RELEASE

You can change `RELEASE` to `DEBUG` if you want a debug build.

Run build command:

    cmake --build .

Install:

    sudo cmake --install .

## Recommended ncurses initialization:

    initscr();
    start_color();
    cbreak();
    noecho();
    nonl();
    keypad(stdscr, TRUE);
    curs_set(0);

```Don't forget to call endwin() at the end of your main function```

## Basic usage

In order to use library you have to create a `Consolengine` object and call a `run()` function on it.
To do so you first need to create a `Window` object.

While you can do it this way:

    Consolengine engine(new Window(10, 10, 0, 0));
    engine.run();

it doesn't really do much because plain window is just an empty square.

```Also, as you might have noticed, I don't free memory allocated for a Window object. This is because the deallocation is happening in the ~Consolengine destructor. Beware of that and don't do delete calls on Windows and Controls yourself```

For any sort of customization on displayed Window you need to create a derived class of it and create it's object
instead.

You can override these functions:

* `render` function to change how your entire window is rendered
* `renderWindowBase` function to change how the base of your window is rendered. By default all controls will be drawn
  on top of that during the `render` function,
* `processInput` function is the main function you'd like to override: this is where you handle input and do some logic
  in response.

You can add controls to your `Window` with `addControl` and remove them with `removeControl`. Initially you'd do that in
constructor but you can also do that in other places.

Right now you can use these controls:

* Button
* TextBlock
* Toggle

Planned controls:

* Slider
* Radio button
* Panel (not sure yet)