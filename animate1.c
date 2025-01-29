
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
    int steps = 70;
    struct color c1 = {35, 41, 108};
    struct color c2 = {114, 159, 252};
    struct color c3 = {66, 149, 214};
    struct color c4 = {166, 226, 252};
    struct color c5 = {192,233,252};
    struct color white = {255,255,255};

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
        gradation_square(c1, c2, 75, 100, 70, 100, i);
        write_Uinside();
        gradation_square(c1, c2, 150, 100, 60, 100, i);
        write_Einside();
        gradation_square(c1, c2, 225, 100, 70, 100, i);
        write_Cinside();

        img_ellipse(c3, 150.0, 100.0, 120.0, 60.0, M_PI / 6.0);
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

        img_fillcircle(c4, x_new, y_new, rad);
        img_fillcircle(c5, x_new-5, y_new+5, rad/2);
        img_fillcircle(white, x_new-7, y_new+7, rad/3);
        
        img_write();
    }
    return 0;
}
