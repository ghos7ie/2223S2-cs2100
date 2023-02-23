#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "q3.h"

#define INTEG_LEN 10
#define FRACT_LEN 6

// Fill in your student ID, name and tutorial group here:

// STUDENT ID (AxxxxxxY): A0253229E
// NAME: LEWIS LYE CHENG SEE
// TUTORIAL GROUP (Txx): T14

void print_bits(int16_t v)
{

    // Pre: y = a 16 bit integer to be printed in binary
    // Post: y is printed in binary

    uint16_t mask = 0b1000000000000000;
    for (int i = 0; i < 16; i++)
    {
        if (v & mask)
            printf("1");
        else
            printf("0");

        mask = mask >> 1;
    }
}

int16_t float_to_fixed(float x)
{

    // Pre: x = a floating point value
    // Returns: The 16-bit 2's complement fixed point representation of x, with 10 bits
    // for the integer part and 6 bits for the fraction part.
    int16_t ans = (int16_t)((x) * (1 << FRACT_LEN));
    return ans;
}

float fixed_to_float(int16_t x)
{
    // Pre: x = a 16-bit 2's complement fixed point number, with
    // 10 bits for the integer part, and 6 bits for the fraction part.
    // Returns: The value of x as a float.
    float ans = ((float)x) / (1 << FRACT_LEN);
    return ans;
}

int16_t negate(int16_t x)
{

    // Pre: x = a 16-bit 2's complement fixed point number, with
    // 10 bits for the integer part, and 6 bits for the fraction part.
    // Returns: -x

    // This operation must be implement strictly using the
    // fixed point representation. If you convert first to
    // floating point, negate then convert back to
    // fixed point, you will get 3 marks deducted.

    return ~x + 1;
}

int16_t add(int16_t x, int16_t y)
{
    // Pre: x and y are 16-bit 2's complement fixed point numbers, with
    // 10 bits for the integer part, and 6 bits for the fraction part.
    // Returns: x + y, again as a 16-bit 2's complement fixed point number
    // with the same format as x and y.

    // This operation must be implement strictly using the
    // fixed point representation. If you convert first to
    // floating point, add then convert back to
    // fixed point, you will get 3 marks deducted.

    int xi = x * (1 << FRACT_LEN);
    int yi = y * (1 << FRACT_LEN);

    int sumi = xi + yi;
    int integ_bits = sumi >> FRACT_LEN;
    int fract_bits = sumi & ((1 << FRACT_LEN) - 1);

    int16_t sum = integ_bits + fract_bits / (1 << FRACT_LEN);
    return sum;
}

int16_t subtract(int16_t x, int16_t y)
{
    // Pre: x and y are 16-bit 2's complement fixed point numbers, with
    // 10 bits for the integer part, and 6 bits for the fraction part.
    // Returns: x - y, again as a 16-bit 2's complement fixed point number
    // with the same format as x and y.

    // This operation must be implement strictly using the
    // fixed point representation. If you convert first to
    // floating point, subtract then convert back to
    // fixed point, you will get 3 marks deducted.

    // basically use negate on y
    // then use add()

    return add(x, negate(y));
}
