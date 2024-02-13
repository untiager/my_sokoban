/*
** EPITECH PROJECT, 2023
** print_gg.c
** File description:
** print_gg.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_gg(va_list list3, int nblen13)
{
    float ent_float = va_arg(list3, double) * 100;
    int before = ent_float;
    int after = ((before) % 100);

    for (int tmp1 = (before / 100); tmp1 != 0; tmp1 /= 10)
        nblen13++;
    for (int tmp2 = after; tmp2 != 0; tmp2 /= 10)
        nblen13++;
    my_put_nbr(before / 100);
    my_putchar('.');
    nblen13++;
    my_put_nbr(after);
    return nblen13;
}
