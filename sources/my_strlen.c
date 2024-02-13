/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return (count);
}
