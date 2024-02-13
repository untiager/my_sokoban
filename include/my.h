/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/sysmacros.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ncurses.h>

typedef struct player {
    int x;
    int y;
}player;
typedef struct holes {
    int x;
    int y;
}holes;
int print_maja(va_list list3, int);
int print_a(va_list list3, int);
int print_gg(va_list lit3, int);
int print_sci_maje(va_list list3, int);
int print_sci_e(va_list list3, int);
int print_pointer(va_list list3, int);
int print_uns_int(va_list list3, int);
int print_float(va_list list3, int);
int print_octal(va_list list3, int);
int print_hexa(va_list list3, int);
int print_percent(va_list list3, int);
int print_dec(va_list list3, int);
int print_int(va_list list3, int);
int print_string(va_list list3, int);
int print_char(va_list list3, int);
void my_putchar(char);
int conv_float_hexa(float);
int my_put_nbr(int);
int my_put_float(float);
int my_put_hexa(int);
int my_putstr(char const *);
int my_strlen(char *);
char *my_revstr(char *);
int my_put_unsnbr(int);
char *my_strncpy(char *, char const *, int);
int my_printf(char *s, ...);
int flag(va_list lits3, char);
char *my_strcpy(char *, char const *);
int my_getnbr(char const *);
int count_line(char **);
int count_col(char **);
char **my_str_to_word_array(char const *);
char **open_map_in_tab(char *fp);
void same_nb(char **);
struct player create_player(char **);
void move_player(char **, player *, int);
void is_there_player(char **);
void rm_player(char **);
void wrong_char_in_map(char **);
void check_box(char **, player *, int);
void write_box(char **, player *, int);
void rm_player_bis(char **, int, int);
void manage_holes(char **, char **, player *);
int nb_boxes(char **);
void double_map(char **);
void get_size(char **);
void center(char *);

#endif /* MY_H_ */
