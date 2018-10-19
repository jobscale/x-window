#include "xMain.h"

void xMain::createNewWindow(int _x, int _y, uint _w, uint _h) {
    int x  = _x;
    int y = _y;
    w = _w;
    h = _h;
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        fprintf(stderr, "Cannot open display.\n");
        exit(1);
    }
    int s;
    gc = DefaultGC(d, s);
    s = DefaultScreen(d);
    window = XCreateSimpleWindow(d, RootWindow(d, s), x, y,  w, h, 1, BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, window, ExposureMask | KeyPressMask | StructureNotifyMask);
    XMapWindow(d, window);
}
void xMain::destroy() {
    XCloseDisplay(d);
}
