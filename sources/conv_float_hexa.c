/*
** EPITECH PROJECT, 2023
** conv float hexa
** File description:
** write a float in hexa
*/

#include "../include/my.h"

int conv_float_hexa(float num)
{
    int i = 0;
    double ent_float = num;
    int before = ent_float;
    double after = ent_float - before;
    int count = 0;

    for (int tmp1 = before; tmp1 != 0; tmp1 /= 10)
        i++;
    my_put_hexa(before);
    my_putchar('.');
    for (count = 0; (int)(after * 10) == 0; after *= 10) {
        my_putchar('0');
        count++;
    }
    for (; count != 6; count++)
        after *= 10;
    if ((int)(after * 10) % 10 >= 5)
        after += 1;
    my_put_hexa(after);
    return (i + 7);
}
