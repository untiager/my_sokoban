/*
** EPITECH PROJECT, 2023
** counting
** File description:
** file for the counting line and col fonction
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include <unistd.h>

int number_line(char *fp)
{
    char mots[1000001];
    int fd = open(fp, O_RDONLY);
    int r = read(fd, mots, 1000000);
    int compteur = 0;
    int nb_line = 0;

    if (fd == -1){
        my_printf("error with open in number_line");
        return 0;
    }
    while (mots[compteur] != '\0'){
        if (mots[compteur] == '\n')
            nb_line++;
        compteur++;
    }
    return nb_line - 1;
}
