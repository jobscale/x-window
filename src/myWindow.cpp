#include "../include/myWindow.h"

void myWindow::createNewWindow(int x, int y, uint w, uint h) {

    d = XOpenDisplay(NULL);

    if(d == NULL) {
        fprintf(stderr, "Cannot open display.\n");
        exit(1);
    }

    window = XCreateSimpleWindow(d, RootWindow(d, s), x, y, w, h, 1, BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, window, ExposureMask | KeyPressMask);
    XMapWindow(d, window);
    s = DefaultScreen(d);
    gc = DefaultGC(d, s);
}

void myWindow::createNewControl(int x, int y, uint w, uint h) {
    XFillRectangle(d, window, gc, x, y, w, h);
    XDrawString(d, window, gc, 10, 50, msg, strlen(msg));
}

void myWindow::destroy() {
    XCloseDisplay(d);
}

int myWindow::run() {
    XNextEvent(d, &e);
    if (e.type == Expose) {
        createNewControl(20,20,10,10);
    }
    if (e.type == KeyPress)
        return 0;
    return 1;
}
