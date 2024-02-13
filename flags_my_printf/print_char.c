/*
** EPITECH PROJECT, 2023
** print_char.c
** File description:
** print_char.c
*/
#include <stdio.h>
#include <stdarg.h>
#include "../include/my.h"

int print_char(va_list list3, int nblen1)
{
    char c = va_arg(list3, int);

    my_putchar(c);
    nblen1++;
    return nblen1;
}
