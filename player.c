/*
** EPITECH PROJECT, 2023
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "include/my.h"

struct player create_player(char **av)
{
    struct player player;
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
        if (maps[count] == 'P'){
            player.x = x - 2;
            player.y = y;
            return player;
        }
    }
    free(maps);
}

void move_player(char **maps, player *player, int b)
{
    if (b == KEY_UP && (maps[player->y - 1][player->x] == ' '
        || maps[player->y - 1][player->x] == 'O')){
        player->y--;
    }
    if (b == KEY_DOWN && (maps[player->y + 1][player->x] == ' '
        || maps[player->y + 1][player->x] == 'O')){
        player->y++;
    }
    if (b == KEY_LEFT && (maps[player->y][player->x - 1] == ' '
        || maps[player->y][player->x - 1] == 'O')){
        player->x--;
    }
    if (b == KEY_RIGHT && (maps[player->y][player->x + 1] == ' '
        || maps[player->y][player->x + 1] == 'O')){
        player->x++;
    }
    mvprintw(player->y, player->x, "P");
}

void rm_player(char **maps)
{
    int ct = 0;
    int i = 0;

    while (maps[ct] != NULL){
        for (i = 0; maps[ct][i] != '\0'; i++){
            rm_player_bis(maps, ct, i);
        }
        ct ++;
    }
}

void rm_player_bis(char **maps, int ct, int i)
{
    if (maps[ct][i] == 'P'){
        maps[ct][i] = ' ';
    }
}
