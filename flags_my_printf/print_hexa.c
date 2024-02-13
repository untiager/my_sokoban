/*
** EPITECH PROJECT, 2023
** print_hexa.c
** File description:
** print_hexa.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_hexa(va_list list3, int nblen7)
{
    int hex = va_arg(list3, int);
    char tab[100] = {0};
    int place;
    char chiffre;

    for (int res = 0; hex > 0; res++) {
        place = hex % 16;
        if (place < 10) {
            chiffre = place + '0';
        } else {
            chiffre = (place - 10) + 'a';
        }
        tab[res] = chiffre;
        hex /= 16;
    }
    nblen7 = my_strlen(tab);
    my_revstr(tab);
    my_putstr(tab);
    return nblen7;
}
