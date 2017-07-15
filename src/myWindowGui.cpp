#include "../include/myWindow.h"


void myWindow::gui() {
    XFillRectangle(d, window, gc, 20, 20, 10, 10);
    XDrawString(d, window, gc, 10, 50, msg, strlen(msg));
}
