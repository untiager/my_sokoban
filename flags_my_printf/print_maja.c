/*
** EPITECH PROJECT, 2023
** print_maja.c
** File description:
** print_maja.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_maja(va_list list3, int nblen15)
{
    int a2 = 0;
    float num2 = va_arg(list3, double);

    while (num2 > 10 || num2 < -10) {
        num2 /= 10;
        a2++;
    }
    my_putstr("0X");
    nblen15 = conv_float_hexa(num2);
    my_putchar('P');
    my_putchar('+');
    my_putchar('0');
    my_put_hexa(a2);
    nblen15 += 5;
    return nblen15;
}
