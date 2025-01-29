#include "img.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void)
{
    struct color c1 = {0, 255, 0};
    struct color c2 = {255, 0, 0};
    struct color black = {0, 0, 0};
    int steps = 100;
    double r = 50.0;

    struct color c = c1;
    struct color d = c2;
    for (int i = 0; i < steps; ++i)
    {
        img_clear();
        img_fillellipse(black, 150.0, 100.0, 100.0, 60.0, M_PI / 6.0);
        double theta = 2 * M_PI * i / steps;
        double sx = sin(theta), cx = cos(theta);
        double rad = 20 - 10 * sx;

        double x = 150 + 100 * cx;
        double y = 100 + 50 * sx;

        // 角度angleだけ回転
        double x_rot = x * cos(M_PI / 6) - y * sin(M_PI / 6);
        double y_rot = x * sin(M_PI / 6) + y * cos(M_PI / 6);

        img_fillcircle(black, x_rot, y_rot, rad);
        write_Uoutside();
        write_Uinside();
        write_Eoutside();
        write_Einside();
        write_Coutside();
        write_Cinside();
        img_write();
    }
    return 0;
}