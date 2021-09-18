// https://rob-blackbourn.github.io/blog/webassembly/wasm/array/arrays/javascript/c/2020/06/07/wasm-arrays.html

#include "maths.h"
#include "walloc.h"
#include "wasm.h"

// extern void jlog(int i);

EXPORT unsigned int *BUFFER;

EXPORT void init(const int w, const int h) {
  BUFFER = malloc(w * h * sizeof(int));
}

// EXPORT double sinx(double x) { return sin(x); };
// EXPORT double cosx(double x) { return cos(x); };

// This wont be callable since it's not exported
int stuff(const int k) { return k; }

EXPORT void draw(const int w, const int h, const int seed,
                 unsigned int *buffer) {
  int x;
  for (x = 0; x < w; x++) {
    int y;
    for (y = 0; y < h; y++) {

      // RGBA in little endian so ABGR
      // 4278190080 to set Alpha to 0xff0000
      unsigned int color =
          (sin((y * y) + (x * x) - seed) * 65280) + 240 + 4278190080;

      // jlog(color);

      buffer[x + y * w] = color; // screen[x][y];
    }
  }
}
