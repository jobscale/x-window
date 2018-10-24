#include "xMain.h"

void Who::Draw() {
  XFillRectangle(display, window, gc, 0, 0, rect.w, rect.h);
  XftDrawStringUtf8(draw, &xColor, xFont, rect.w / 4, rect.h / 2, (const FcChar8*)text, (int)strlen(text));
}

void Who::ChangeWindow(XConfigureEvent& xconfigure) {
  if (rect.w != (uint)xconfigure.width || rect.h != (uint)xconfigure.height) {
    rect.w = xconfigure.width;
    rect.h = xconfigure.height;
  }
}
