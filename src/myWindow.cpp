#include "../include/myWindow.h"

void myWindow::createNewWindow(int _x, int _y, uint _w, uint _h) {

    x  = _x;
    y = _y;
    w = _w;
    h = _h;

    d = XOpenDisplay(NULL);

    if(d == NULL) {
        fprintf(stderr, "Cannot open display.\n");
        exit(1);
    }
    gc = DefaultGC(d, s);
    s = DefaultScreen(d);
    window = XCreateSimpleWindow(d, RootWindow(d, s), x, y,  w, h, 1, BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, window, ExposureMask | KeyPressMask | StructureNotifyMask);
    XMapWindow(d, window);
}

void myWindow::destroy() {
    XCloseDisplay(d);
}
