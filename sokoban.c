/*
** EPITECH PROJECT, 2023
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "include/my.h"

char **open_map_in_tab(char *fp)
{
    char *buff = malloc(10000);
    int opn = open(fp, O_RDONLY);
    int rd = read(opn, buff, 10000);
    char **maps = my_str_to_word_array(buff);

    if (opn == -1) {
        my_printf("error with open\n");
        exit(84);
    }
    if (rd == -1){
        my_printf("error with read\n");
        exit(84);
    }
    free(buff);
    close(opn);
    return maps;
}

void display_map(char **av)
{
    player player = create_player(av);
    int b;
    char **maps = open_map_in_tab(av[1]);

    initscr();
    keypad(stdscr, 1);
    curs_set(0);
    refresh();
    rm_player(maps);
    while (b != 'q') {
        check_box(maps, &player, b);
        for (int i = 0; maps[i] != NULL; i++)
            printw("%s", maps[i]);
        move_player(maps, &player, b);
        manage_holes(maps, av, &player);
        refresh();
        b = getch();
        clear();
    }
    endwin();
}

void flag_h(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h'){
        write(1, "If you want to play, please enter ./my_sokoban ", 48);
        write(1, "followed by the map you want to play\n", 38);
        write(1, "A map can only have one player and should be ", 46);
        write(1, "only made of '#' and 'X' and 'O' and 'P'\n", 42);
        write(1, "The 'P' represent the player, ", 31);
        write(1, "the '#' represent the walls.\n", 30);
        write(1, "You can exit the game by pressing 'q'\n", 39);
        write(1, "Move the boxes(X) in the holes(O)", 34);
        write(1, " without putting the boxes in the corner.\n", 43);
        write(1, "Be careful when moving the boxes!! ", 36);
        write(1, "If you think you are stuck, restart the game.\n", 47);
        write(1, "Ps : The player is a lot thinner than it seems\n", 48);
        exit(0);
    }
}

void error_handling(int ac, char **av)
{
    if (ac != 2) {
        write(1, "error with number of arguments\n", 32);
        exit(84);
    }
    flag_h(av);
    same_nb(av);
    wrong_char_in_map(av);
    is_there_player(av);
}

int main(int ac, char **av)
{
    error_handling(ac, av);
    display_map(av);
    return 0;
}
