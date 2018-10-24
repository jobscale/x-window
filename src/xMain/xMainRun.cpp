#include "xMain.h"

int Who::Run() {
  XEvent event;
  for (;;) {
    for (; XPending(display) > 0;) {
      XNextEvent(display, &event);
      if (OnEvent(event)) {
        return 0;
      }
    }
  }
}

void Who::CheckKey(int type, KeySym sym) {
  if (sym == XK_Control_L || sym == XK_Control_R) {
    ctrl_flag = type == KeyPress;
  } else if (ctrl_flag) {
    switch (sym) {
      case XK_q:
      case XK_w:
      case XK_e:
        Destroy();
        break;
      default:
        break;
    }
  }
}
