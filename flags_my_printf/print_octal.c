/*
** EPITECH PROJECT, 2023
** print_octal.c
** File description:
** print_octal.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_octal(va_list list3, int nblen6)
{
    int dec = va_arg(list3, int);
    int octal = 0;

    for (int i = 1; dec != 0; i *= 10) {
        octal += (dec % 8) * i;
        dec /= 8;
    }
    for (int tmp2 = octal; tmp2 != 0; tmp2 /= 10)
        nblen6++;
    my_put_nbr(octal);
    return nblen6;
}
