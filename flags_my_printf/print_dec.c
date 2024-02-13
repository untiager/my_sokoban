/*
** EPITECH PROJECT, 2023
** print_dec.c
** File description:
** print_dec.c
*/
#include <stdio.h>
#include <stdarg.h>
#include "../include/my.h"

int print_dec(va_list list3, int nblen4)
{
    int i = va_arg(list3, int);

    for (int tmp2 = i; tmp2 != 0; tmp2 /= 10)
        nblen4++;
    my_put_nbr(i);
    return nblen4;
}
