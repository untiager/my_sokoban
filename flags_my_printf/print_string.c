/*
** EPITECH PROJECT, 2023
** print_string.c
** File description:
** print_string.c
*/
#include <stdio.h>
#include <stdarg.h>
#include "../include/my.h"

int print_string(va_list list3, int nblen2)
{
    char *str = va_arg(list3, char *);

    my_putstr(str);
    nblen2 += my_strlen(str);
    return nblen2;
}
