/*
** EPITECH PROJECT, 2023
** my put hexa
** File description:
** print an hexa from a int
*/

#include "../include/my.h"

int my_put_hexa(int nb)
{
    int i = 0;
    int hex = nb;
    char tab[100] = {0};
    int place;
    char chiffre;

    for (int res = 0; hex > 0; res++) {
        place = hex % 16;
        if (place < 10) {
            chiffre = place + '0';
        } else {
            chiffre = (place - 10) + 'A';
        }
        tab[res] = chiffre;
        hex /= 16;
    }
    i = my_strlen(tab);
    my_revstr(tab);
    my_putstr(tab);
    return i;
}
