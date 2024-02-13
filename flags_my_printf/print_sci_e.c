/*
** EPITECH PROJECT, 2023
** print_sci_e.c
** File description:
** print_sci_e.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_sci_e(va_list list3, int nblen11)
{
    int i = 0;
    float num = va_arg(list3, double);

    while (num > 10 || num < -10) {
        num /= 10;
        i++;
    }
    nblen11 = my_put_float(num);
    my_putchar('e');
    my_putchar('+');
    my_putchar('0');
    my_put_nbr(i);
    nblen11 += 4;
    return nblen11;
}
