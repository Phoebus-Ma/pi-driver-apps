/**
 * calculate.c
 * This file provides simple numerical calculations and returns the results.
 * 
 * License - GPL-2.0.
*/

#include <linux/module.h>

#include "calculate.h"


inline int
hello_add(int a, int b)
{
    return ((a) + (b));
}

inline int
hello_sub(int a, int b)
{
    return ((a) - (b));
}

inline int
hello_mul(int a, int b)
{
    return ((a) * (b));
}

inline int
hello_div(int a, int b)
{
    return ((a) / (b));
}

inline int
hello_mod(int a, int b)
{
    return ((a) % (b));
}

MODULE_LICENSE("GPL");
