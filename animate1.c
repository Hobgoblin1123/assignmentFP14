
// animate1 --- create animation using img lib.
#include "img.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  struct color c1 = {0, 255, 0};
  struct color c2 = {255, 0, 0};
  struct color black = {0, 0, 0};
  int i,x;
  // for (i = 0; i < 20; ++i)
  // {
  //   img_clear();
  //   black.r += i*10; black.g += i*10; black.b += i*10;
  //   img_fillcircle(black, 20 + i * 8, 100, 20);
  //   img_write();
  // }
  // for (i = 0; i < 20; ++i)
  // {
  //   img_clear();
  //   img_fillcircle(c2, 180, 100 + i * 5, 20 - i);
  //   img_write();
  // }
  for (i=0; i<25; ++i){
    img_clear();
    gradation_square(c1, c2, 150, 100, 50);
    img_write();
  }
  return 0;
}