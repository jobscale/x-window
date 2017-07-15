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
    const char *msg = "HelloWorld";
    int s;

    public:;
    void createNewWindow(int x, int y, uint w, uint h);
    void createNewControl(int x, int y, uint w, uint h);
    void destroy();
    int run();
};

#endif //_MYWINDOW_H
