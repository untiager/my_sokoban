/*
** EPITECH PROJECT, 2023
** my_put_unsnbr.c
** File description:
** my_put_unsnbr.c
*/
#include "../include/my.h"

int my_put_unsnbr(int nb)
{
    unsigned int d;

    d = 1;
    while ((nb / d) >= 10)
        d *= 10;
    while (d > 0) {
        my_putchar((nb / d) % 10 + '0');
        d /= 10;
    }
}
