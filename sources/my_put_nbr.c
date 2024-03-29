/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/
#include "../include/my.h"

int my_put_nbr(int nb)
{
    int d;

    d = 1;
    if (nb == -2147483648)
        my_putstr("-2147483648");
    else {
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        }
        while ((nb / d) >= 10)
            d *= 10;
        while (d > 0) {
            my_putchar((nb / d) % 10 + '0');
            d /= 10;
        }
    }
}
