#include "clock.h"

int main() {
  Clock c = Clock();
  c.PrintTime(true);

  c = Clock(13, -24, 10);
  c.PrintUsTime(true);
  c.PrintTime(true);
  for(int i = 0; i < 24; i++) {
    Clock c1 = Clock(i, 0, 0);
    c1.PrintTime(true);
    c1.PrintUsTime(true);
  }
}
