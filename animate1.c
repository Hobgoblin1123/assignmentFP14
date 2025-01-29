
// animate1 --- create animation using img lib.
#include "img.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void)
{
    struct color black = {0, 0, 0};
    int steps = 50;
    struct color c1 = {35, 41, 108};
    struct color c2 = {114, 159, 252};

    // for (int i = 0; i < steps; ++i) {
    //     img_clear();
    //     gradation_square(c1, c2, 75, 100, 35, 50, i);
    //     img_write();
    // }

    // for(int i= 0; i < steps; ++i){
    //     img_clear();
    //     write_U();
    //     img_write();
    // }

    for (int i = 0; i < steps; ++i)
    {
        img_clear();
        gradation_square(c1, c2, 75, 100, 35, 50, i);
        img_ellipse(black, 150.0, 100.0, 100.0, 60.0, M_PI / 6.0);
        double theta = 2 * M_PI * i / steps;
        double sx = sin(theta), cx = cos(theta);
        double rad = 20 - 10 * sx;

        double x = 150 + 100 * cx;
        double y = 100 + 50 * sx;

         // (150,100) を中心
         double x_shifted = x - 150;
         double y_shifted = y - 100;

        // 回転角度を決定
        double x_rot = x_shifted * cos(M_PI / 6) - y_shifted * sin(M_PI / 6);
        double y_rot = x_shifted * sin(M_PI / 6) + y_shifted * cos(M_PI / 6);

        // 回転の中心を楕円の中心に
        double x_new = x_rot + 150;
        double y_new = y_rot + 100;

        img_fillcircle(c2, x_new, y_new, rad);
        img_write();
    }
    return 0;
}
