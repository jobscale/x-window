#include "xMain.h"

bool Who::OnEvent(XEvent& event) {
  switch (event.type) {
    case Expose:
      Draw();
      break;
    case KeyPress:
    case KeyRelease:
      CheckKey(event.type, XLookupKeysym(&event.xkey, 0));
      break;
    case ClientMessage:
      if ((Atom)event.xclient.data.l[0] == wm_delete_window) {
        Destroy();
      }
      break;
    case DestroyNotify:
      Terminate();
      return true;
    case MappingNotify:
      XRefreshKeyboardMapping(&event.xmapping);
      break;
    case ConfigureNotify:
      ChangeWindow(event.xconfigure);
      break;
    case MapNotify:
      printf("MapNotify Event.\n");
      break;
    case UnmapNotify:
      printf("UnmapNotify Event.\n");
      break;
    case ReparentNotify:
      printf("ReparentNotify Event.\n");
      break;
    default:
      fprintf(stderr, "Unknown Event (event.type : %display)\n", event.type);
      break;
  }
  return false;
}
