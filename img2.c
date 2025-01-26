#include <stdio.h>
#include <stdlib.h>
#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];


void gradation_square(struct color c, struct color d, double x, double y, double r, int step) {
    int imin = (int)(x - r/2 - 1), imax = (int)(x + r/2 + 1);
    int jmin = (int)(y - r/2 - 1), jmax = (int)(y + r/2 + 1);
    int i, j;
    struct color initial_c = c;
    double n_r = (double)(d.r - c.r) / (jmax - jmin);  //始値と終値間のyの1座標辺りの色の幅
    double n_g = (double)(d.g - c.g) / (jmax - jmin);
    double n_b = (double)(d.b - c.b) / (jmax - jmin);

    for(j = jmin; j <= jmax; ++j) {
        int shifted_j = j + step;  //step...初期移動幅、shifted_j...その時の、jの底辺(jmin)からの移動幅
        if (shifted_j > jmax) {
            shifted_j = jmin + (shifted_j - jmax - 1);  //移動幅が(jmax-jmin)を越えたら移動幅を0から数えなおす
        }
        c.r = initial_c.r + (shifted_j - jmin) * n_r;  //移動幅分のrgb値を足す
        c.g = initial_c.g + (shifted_j - jmin) * n_g;
        c.b = initial_c.b + (shifted_j - jmin) * n_b;
        for(i = imin; i <= imax; ++i) {
            img_putpixel(c, i, j);
        }
    }
}
