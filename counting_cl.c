/*
** EPITECH PROJECT, 2023
** counting_holes.c
** File description:
** the file for the fonction that
** count the number of hole from the map for my_sokoban
*/

#include "include/my.h"

int count_col(char **av)
{
    char *maps = malloc(10000);
    int opn = open(av[1], O_RDONLY);
    int rd = read(opn, maps, 10000);
    int ct = 0;

    while (maps[ct] != '\0'){
        if (maps[ct] == '\n'){
            return ct;
        }
        ct++;
    }
    close(opn);
}

int count_line(char **av)
{
    char *maps = malloc(10000);
    int opn = open(av[1], O_RDONLY);
    int rd = read(opn, maps, 10000);
    int ct = 0;
    int ct_line = 0;

    while (maps[ct] != '\0'){
        if (maps[ct] == '\n')
            ct_line++;
        ct++;
    }
    close(opn);
    return ct_line;
}
