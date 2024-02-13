/*
** EPITECH PROJECT, 2023
** counting_holes.c
** File description:
** the file for the fonction that
** count the number of hole from the map for my_sokoban
*/

#include "include/my.h"

int nb_holes(char **av)
{
    char *maps = malloc(10000);
    int opn = open(av[1], O_RDONLY);
    int rd = read(opn, maps, 10000);
    int ct = 0;
    int num_holes = 0;

    while (maps[ct] != '\0'){
        if (maps[ct] == 'O')
            num_holes++;
        ct++;
    }
    free(maps);
    close(opn);
    return num_holes;
}

int nb_boxes(char **av)
{
    char *maps = malloc(10000);
    int opn = open(av[1], O_RDONLY);
    int rd = read(opn, maps, 10000);
    int ct = 0;
    int num_boxes = 0;

    while (maps[ct] != '\0'){
        if (maps[ct] == 'X')
            num_boxes++;
        ct++;
    }
    free(maps);
    close(opn);
    return num_boxes;
}

void same_nb(char **av)
{
    int num_boxes = nb_boxes(av);
    int num_holes = nb_holes(av);

    if (num_boxes != num_holes || num_boxes == 0 || num_holes == 0){
        write(1, "not the same number of holes and box\n", 38);
        exit(84);
    }
}

void is_there_player(char **av)
{
    char *maps = malloc(10000);
    int opn = open(av[1], O_RDONLY);
    int rd = read(opn, maps, 10000);
    int ct = 0;
    int ct_p = 0;

    while (maps[ct] != '\0'){
        if (maps[ct] == 'P')
            ct_p ++;
        ct ++;
    }
    if (ct_p != 1){
        my_printf("no player in the map\n");
        exit(84);
    }
    free(maps);
    close(opn);
}

void wrong_char_in_map(char **av)
{
    char *maps = malloc(10000);
    int opn = open(av[1], O_RDONLY);
    int rd = read(opn, maps, 10000);
    int ct = 0;
    int ct_error = 0;

    while (maps[ct] != '\0'){
        if (maps[ct] != ' ' && maps[ct] != 'X' && maps[ct] != '#'
            && maps[ct] != 'P' && maps[ct] != 'O' && maps[ct] != '\n')
            ct_error++;
        ct++;
    }
    if (ct_error != 0){
        write(1, "incorrect char in the map\n", 27);
        exit(84);
    }
    free(maps);
    close(opn);
}
