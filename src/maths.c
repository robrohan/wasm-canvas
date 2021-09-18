#include "maths.h"

// https://stackoverflow.com/questions/18662261/fastest-implementation-of-sine-cosine-and-square-root-in-c-doesnt-need-to-b
double cos(double x) {
  if (x < 0) {
    int q = -x / DOUBLE_PI;
    q += 1;
    double y = q * DOUBLE_PI;
    x = -(x - y);
  }
  if (x >= DOUBLE_PI) {
    int q = x / DOUBLE_PI;
    double y = q * DOUBLE_PI;
    x = x - y;
  }
  int s = 1;
  if (x >= PI) {
    s = -1;
    x -= PI;
  }
  if (x > HALF_PI) {
    x = PI - x;
    s = -s;
  }
  double z = x * x;
  double r = z * (z * (SIN_CURVE_A - SIN_CURVE_B * z) - 0.5) + 1.0;
  if (r > 1.0)
    r = r - 2.0;
  if (s > 0)
    return r;
  else
    return -r;
}

double sin(double x) { return cos(x - HALF_PI); }
