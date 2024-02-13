/*
** EPITECH PROJECT, 2023
** print_sci_maje.c
** File description:
** print_sci_maje.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_sci_maje(va_list list3, int nblen12)
{
    int i = 0;
    float num = va_arg(list3, double);

    while (num > 10 || num < -10) {
        num /= 10;
        i++;
    }
    nblen12 = my_put_float(num);
    my_putchar('E');
    my_putchar('+');
    my_putchar('0');
    my_put_nbr(i);
    nblen12 += 4;
    return nblen12;
}
