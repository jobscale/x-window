#include "xMain.h"

Who::Who() {
  Rect rect = Rect(0, 0, 300, 300);
  window = XCreateSimpleWindow(display, RootWindow(display, 0), rect.x, rect.y, rect.w, rect.h, 1, black, white);
  XSetWMProtocols(display, window, &wm_delete_window, 1);
  XMapWindow(display, window);
  XSelectInput(display, window, ExposureMask | KeyPressMask | KeyReleaseMask | StructureNotifyMask);
  gc = XCreateGC(display, window, 0, 0);
  cmap = DefaultColormap(display, 0);
  XftColorAllocName(display, DefaultVisual(display, 0), cmap, color, &xColor);
  draw = XftDrawCreate(display, window, DefaultVisual(display, 0), cmap);
  xFont = XftFontOpen(display, 0, XFT_FAMILY, XftTypeString, fontFamily, XFT_SIZE, XftTypeDouble, 24.0, 0);
}

Who::~Who() {
  XSetCloseDownMode(display, DestroyAll);
  XCloseDisplay(display);
}

void Who::Terminate() {
  delete this;
}

void Who::Destroy() {
  XftDrawDestroy(draw);
  XDestroyWindow(display, window);
}
