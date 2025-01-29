
// animate1 --- create animation using img lib.
#include "img.h"
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
    struct color c1 = {0, 255, 0};
    struct color c2 = {255, 0, 0};
    struct color black = {0, 0, 0};
    int steps = 100;
    double r = 50.0;

    struct color c = c1;
    struct color d = c2;

    // for (int i = 0; i < steps; ++i) {
    //     img_clear();
    //     gradation_square(c, d, 150, 100, r, i);
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
        img_fillellipse(black, 150.0, 100.0, 100.0, 60.0, M_PI / 6.0);
        write_Uoutside();
        img_write();
    }

    return 0;
}
