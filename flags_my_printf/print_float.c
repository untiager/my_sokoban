/*
** EPITECH PROJECT, 2023
** print_float.c
** File description:
** print_float.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_float(va_list list3, int nblen9)
{
    double ent_float = va_arg(list3, double);
    int before = ent_float;
    double after = ent_float - before;
    int count = 0;

    for (int tmp1 = before; tmp1 != 0; tmp1 /= 10)
        nblen9++;
    my_put_nbr(before);
    my_putchar('.');
    for (count = 0; (int)(after * 10) == 0; after *= 10) {
        my_putchar('0');
        count++;
    }
    for (; count != 6; count++)
        after *= 10;
    if ((int)(after * 10) % 10 >= 5)
        after += 1;
    my_put_nbr(after);
    return (nblen9 + 7);
}
