/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** my_revstr.c
*/
#include "../include/my.h"

char *my_revstr(char *str)
{
    int s = my_strlen(str) - 1;
    char c;

    for (int j = 0; j < s; j++) {
        c = str[j];
        str[j] = str[s];
        str[s] = c;
        s--;
    }
    return (str);
}
