/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;
    int j = 4;

    while (a != n) {
        dest[a] = src[j];
        a++;
        j++;
    }
    dest[a] = '\0';
    return (dest);
}
