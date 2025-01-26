#include <stdio.h>
#include <stdlib.h>
#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

void gradation_square(struct color c, struct color d, double x, double y, double r){
  int imin = (int)(x - r/2 - 1), imax = (int)(x + r/2 + 1);
  int jmin = (int)(y - r/2 - 1), jmax = (int)(y + r/2 + 1);
  int i, j;
  struct color initial_c = c; struct color initial_d = d;
  double n_r = (d.r-c.r)/r; double n_g = (d.g-c.g)/r; double n_b = (d.b-c.b)/r;
  for(j = jmin; j <= jmax; ++j) {
    if(j < jmax){
        c.r = initial_c.r + (j-jmin)*(int)n_r; c.g = initial_c.g + (j-jmin)*(int)n_g; c.b = initial_c.b + (j-jmin)*(int)n_b;
    }
    for(i = imin; i <= imax; ++i) {
      img_putpixel(c,i,j);
    }
  }
}
