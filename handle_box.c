/*
** EPITECH PROJECT, 2023
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "include/my.h"

void check_box(char **maps, player *player, int b)
{
    if (b == KEY_UP && maps[player->y - 1][player->x] == 'X'
    && maps[player->y - 2][player->x] != '#'
    && maps[player->y - 2][player->x] != 'X'){
        maps[player->y - 2][player->x] = 'X';
        maps[player->y - 1][player->x] = ' ';
    }
    if (b == KEY_DOWN && maps[player->y + 1][player->x] == 'X'
    && maps[player->y + 2][player->x] != '#'
    && maps[player->y + 2][player->x] != 'X'){
        maps[player->y + 2][player->x] = 'X';
        maps[player->y + 1][player->x] = ' ';
    }
    write_box(maps, player, b);
}

void write_box(char **maps, player *player, int b)
{
    if (b == KEY_LEFT && maps[player->y][player->x - 1] == 'X'
    && maps[player->y][player->x - 2] != '#'
    && maps[player->y][player->x - 2] != 'X'){
        maps[player->y][player->x - 2] = 'X';
        maps[player->y][player->x - 1] = ' ';
    }
    if (b == KEY_RIGHT && maps[player->y][player->x + 1] == 'X'
    && maps[player->y][player->x + 2] != '#'
    && maps[player->y][player->x + 2] != 'X'){
        maps[player->y][player->x + 2] = 'X';
        maps[player->y][player->x + 1] = ' ';
    }
}

struct holes create_holes(char **av)
{
    struct holes holes;
    char *maps = malloc(10000);
    int opn = open(av[1], O_RDWR);
    int rd = read(opn, maps, 10000 - 1);
    int x = 0;
    int y = 0;

    for (int count = 0; maps[count] != '\0'; count ++){
        if (maps[count] == '\n'){
            x = 0;
            y++;
        }
        x++;
        if (maps[count] == 'O'){
            holes.x = x - 2;
            holes.y = y;
            return holes;
        }
    }
    free(maps);
}

static void win_condition2(char **maps, int ct, int ct2, int *ct_o)
{
    if (maps[ct][ct2] == 'O')
        *ct_o += 1;
}

void win_condition(char **maps, player *player)
{
    int ct = 0;
    int ct2 = 0;
    int ct_o = 0;

    while (maps[ct] != NULL){
        for (ct2 = 0; maps[ct][ct2]; ct2++){
            win_condition2(maps, ct, ct2, &ct_o);
        }
        ct++;
    }
    if (ct_o == 0){
        endwin();
        for (int i = 0; maps[i] != NULL; i++){
            maps[player->y][player->x] = 'P';
            my_printf("%s", maps[i]);
        }
        exit(0);
    }
}

void manage_holes(char **maps, char **av, player *player)
{
    holes holes = create_holes(av);

    get_size(av);
    if (maps[holes.y][holes.x] == ' '){
        maps[holes.y][holes.x] = 'O';
    }
    win_condition(maps, player);
}
