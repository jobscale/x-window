#include "myWindow.h"

myWindow win;

int main(int argc, char **argv) {

    win.createNewWindow(100, 100, 1000, 1000);

    while(win.run()) {

    }
    return 1;
}
