
// animate1 --- create animation using img lib.
#include "img.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct color c1 = {0, 255, 0};
    struct color c2 = {255, 0, 0};
    int steps = 100;
    double r = 50.0;
    
    struct color c = c1; 
    struct color d = c2; 

    for (int i = 0; i < steps; ++i) {
        img_clear();
        gradation_square(c, d, 150, 100, r, i);
        img_write();
    }

    return 0;
}

