#include "../include/myWindow.h"

int myWindow::run() {
    while(XPending(d) > 0) {
        XNextEvent(d, &e);

        switch(e.type) {
            case Expose:
            gui();
            break;

        case ConfigureNotify:
            if(w != (uint)e.xconfigure.width || h != (uint)e.xconfigure.height) {
                w = e.xconfigure.width;
                h = e.xconfigure.height;
            }
            break;

         case KeyPress:
            destroy();
            return 0;
        }
    }
    return 1;
}
