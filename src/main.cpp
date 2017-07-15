#include "../include/myWindow.h"

myWindow win;

int main(int argc, char **argv) {

    win.createNewWindow(10, 10, 100, 100);

    while(win.run()){}
    win.destroy();
    return 1;
}
