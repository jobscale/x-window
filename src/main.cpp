#include "xMain/xMain.h"

xMain win;

int main(int argc, char **argv) {
    win.createNewWindow(100, 100, 1000, 1000);
    for (; win.run(); ) ;
    return 0;
}
