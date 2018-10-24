#ifndef __X_MAIN__
#define __X_MAIN__

#include <stdio.h>
#include <X11/Xutil.h>
#include <X11/Xft/Xft.h>

struct Rect {
  Rect(int _x, int _y, uint _w, uint _h) {
    x = _x; y = _y; w = _w; h = _h;
  }
  int x = 0;
  int y = 0;
  uint w = 0;
  uint h = 0;
};

class WinBase {
protected:
  const char* text = "こん";
  const char* color = "blue";
  const char* fontFamily = "VL ゴシック";
  Display *const display = XOpenDisplay(NULL);
  Atom wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
  Rect rect = Rect(0, 0, 300, 300);
  const unsigned long black = BlackPixel(display, 0);
  const unsigned long white = WhitePixel(display, 0);
  Bool ctrl_flag = False;
  GC gc;
  Window window;
  Colormap cmap;
  XftColor xColor;
  XftFont* xFont;
  XftDraw* draw;
};

class Who : WinBase {
public:
  Who();
  virtual ~Who();
  int Run();
  void Destroy();
protected:
  void Terminate();
  void Draw();
  void CheckKey(int type, KeySym sym);
  void ChangeWindow(XConfigureEvent& xconfigure);
  bool OnEvent(XEvent& event);
};

#endif // __X_MAIN__
