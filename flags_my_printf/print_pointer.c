/*
** EPITECH PROJECT, 2023
** print_pointer.c
** File description:
** print_pointer.c
*/
#include "../include/my.h"
#include <stdarg.h>

int print_pointer(va_list list3, int nblen10)
{
    unsigned int point = va_arg(list3, unsigned int);
    char tab[100] = {0};
    char chiffre = 0;
    int place = 0;

    for (int res = 0; point > 0; res++) {
        place = point % 16;
        if (place < 10) {
            chiffre = place + '0';
        } else
            chiffre = (place - 10) + 'A';
        tab[res] = chiffre;
        point /= 16;
    }
    nblen10 = my_strlen(tab);
    my_putstr("0x");
    nblen10 = nblen10 + 2;
    my_putstr(my_revstr(tab));
    return nblen10;
}
