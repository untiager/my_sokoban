/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** my_printf.c
*/
#include <stdio.h>
#include <stdarg.h>
#include "include/my.h"

int flag(va_list list3, char c)
{
    int nblen = 0;
    char *flags = "csid%oxXufFpeEgGaA";
    int (*t[])(va_list, int) = {print_char, print_string,
        print_int, print_dec, print_percent, print_octal,
        print_hexa, print_hexa, print_uns_int, print_float,
        print_float, print_pointer, print_sci_e, print_sci_maje,
        print_gg, print_gg, print_a, print_maja};

    for (int p = 0; p < my_strlen(flags); p++) {
        if (flags[p] == c){
            nblen += t[p](list3, nblen);
        }
    }
    return nblen;
}

int my_printf(char *s, ...)
{
    int nblen0 = 0;
    va_list list3;

    va_start(list3, s);
    for (int h = 0; h < my_strlen(s); h++) {
        if (s[h] != '%') {
            my_putchar(s[h]);
            nblen0++;
        }
        if (s[h] == '%') {
            nblen0 += flag(list3, s[h + 1]);
            h++;
        }
    }
    va_end(list3);
}
