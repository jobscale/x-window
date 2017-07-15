#ifndef _MYWINDOW_H
#define _MYWINDOW_H

#include <X11/Xlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class myWindow {
private:
    Window window;
    Display *d;
    XEvent e;
    GC gc;
    int s, x, y;
    uint w, h;
    const char *msg = "HelloWorld";

public:
    void createNewWindow(int _x, int _y, uint _w, uint _h);
    void gui();
    void destroy();
    int run();
};

#endif //_MYWINDOW_H
