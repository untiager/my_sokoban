/*
** EPITECH PROJECT, 2023
** print_int.c
** File description:
** print_int.c
*/
#include <stdio.h>
#include <stdarg.h>
#include "../include/my.h"

int print_int(va_list list3, int nblen3)
{
    int i = va_arg(list3, int);

    for (int tmp2 = i; tmp2 != 0; tmp2 /= 10)
        nblen3++;
    my_put_nbr(i);
    return nblen3;
}
