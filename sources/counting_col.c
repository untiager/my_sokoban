/*
** EPITECH PROJECT, 2023
** counting
** File description:
** file for the number of char per line
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include <unistd.h>

int nb_col(char *fp)
{
    char mots[1000001];
    int fd = open(fp, O_RDONLY);
    int r = read(fd, mots, 1000000);
    int compteur = 0;
    int nb_col = 0;
    int compteur_first_line = 0;
    int compteur_first_col = 0;

    while (mots[compteur_first_col] != '\n')
        compteur_first_col++;
    while (mots[compteur] != '\0'){
        nb_col++;
        compteur++;
        if (mots[compteur] == '\n')
            compteur_first_line++;
        if (mots[compteur] == '\n' && compteur_first_line == 2){
            nb_col -= compteur_first_col;
            return nb_col - 1;
        }
    }
}
