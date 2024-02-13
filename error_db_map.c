/*
** EPITECH PROJECT, 2023
** counting_holes.c
** File description:
** the file for the fonction that
** count the number of hole from the map for my_sokoban
*/

#include "include/my.h"

void double_map(char **av)
{
    char *maps = malloc(10000);
    int opn = open(av[1], O_RDONLY);
    int rd = read(opn, maps, 10000);
    int ct = 0;

    while (maps[ct] != '\0'){
        if (maps[ct] == '\n' && maps[ct + 1] == '\n'){
            write(1, "double map\n", 11);
            exit(84);
        }
        ct++;
    }
    free(maps);
    close(opn);
}

void center(char *str)
{
    int x = (COLS / 2) - (my_strlen(str) / 2);
    int y = LINES / 2;

    mvprintw(y, x, str);
}

void get_size(char **av)
{
    int nb_line = count_line(av);
    int nb_col = count_col(av);

    if (COLS < nb_col || LINES < nb_line){
        clear();
        center("\nPlease change the size of your terminal\n");
        refresh();
    }
}
