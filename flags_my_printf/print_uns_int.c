/*
** EPITECH PROJECT, 2023
** print_uns_int.c
** File description:
** print_uns_int.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_uns_int(va_list list3, int nblen8)
{
    unsigned int uns = va_arg(list3, int);

    for (int tmp2 = uns; tmp2 != 0; tmp2 /= 10)
        nblen8++;
    my_put_unsnbr(uns);
    return nblen8;
}
