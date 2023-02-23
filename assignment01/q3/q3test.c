#include <stdio.h>
#include <stdint.h>
#include "q3.h"

int main() {
    float x, y, ra, rs;
    int16_t fixed_x, fixed_y, add_res, sub_res;
    float float_x, float_y, float_add, float_sub;

    printf("\nEnter x and y: ");
    scanf("%f %f", &x, &y);

    fixed_x = float_to_fixed(x);
    float_x = fixed_to_float(fixed_x);
    fixed_y = float_to_fixed(y);
    float_y = fixed_to_float(fixed_y);

    printf("\n\nx: %f fixed_x: %d float_x: %f Error: %f\n", x, fixed_x, float_x, x - float_x);
    printf("y: %f fixed_y: %d float_y: %f Error: %f\n", y, fixed_y, float_y, y - float_y);

    add_res = add(fixed_x, fixed_y);
    sub_res = subtract(fixed_x, fixed_y);

    printf("\nx = ");
    print_bits(fixed_x);
    printf(" y = ");
    print_bits(fixed_y);
    printf(" x + y = ");
    print_bits(add_res);
    printf(" x - y = ");
    print_bits(sub_res);

    printf("\n\n");

    float_add = fixed_to_float(add_res);
    float_sub = fixed_to_float(sub_res);

    ra = x + y;
    rs = x - y;

    printf("\nx: %f y: %f x + y: %f fixed_x + fixed_y = %f fixed_err = %f\n\n",
    x, y, ra,  float_add, ra - float_add);

    printf("\nx: %f y: %f x - y: %f fixed_x - fixed_y = %f fixed_err = %f\n\n",
    x, y, rs, float_sub, rs - float_sub);
}


