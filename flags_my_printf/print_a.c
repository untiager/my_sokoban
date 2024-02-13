/*
** EPITECH PROJECT, 2023
** print_a.c
** File description:
** print_a.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_a(va_list list3, int nblen14)
{
    int a = 0;
    float num1 = va_arg(list3, double);

    while (num1 > 10 || num1 < -10) {
        num1 /= 10;
        a++;
    }
    my_putstr("0x");
    nblen14 = conv_float_hexa(num1);
    my_putchar('p');
    my_putchar('+');
    my_putchar('0');
    my_put_hexa(a);
    nblen14 += 5;
    return nblen14;
}
