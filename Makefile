##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	sources/my_strlen.c \
		sources/my_putstr.c \
		sources/my_putchar.c \
		sources/my_put_nbr.c \
		sources/my_put_unsnbr.c \
		sources/my_revstr.c \
		sources/my_put_float.c \
		sources/my_put_hexa.c \
		sources/conv_float_hexa.c \
		sources/my_strcpy.c \
		sources/my_strncpy.c \
		sources/my_getnbr.c \
		sources/counting_col.c \
		sources/counting_line.c \
		sources/my_str_to_word_array.c \
		flags_my_printf/print_char.c \
		flags_my_printf/print_int.c \
		flags_my_printf/print_percent.c \
		flags_my_printf/print_string.c \
		flags_my_printf/print_dec.c \
		flags_my_printf/print_hexa.c \
		flags_my_printf/print_float.c \
		flags_my_printf/print_pointer.c \
		flags_my_printf/print_uns_int.c \
		flags_my_printf/print_octal.c \
		flags_my_printf/print_sci_e.c \
		flags_my_printf/print_sci_maje.c \
		flags_my_printf/print_gg.c \
		flags_my_printf/print_a.c \
		flags_my_printf/print_maja.c \
		counting_holes.c \
		player.c \
		counting_cl.c \
		handle_box.c \
		error_db_map.c \
		my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -g3 -o  my_sokoban sokoban.c -L/usr/lib -lncurses -L. -lmy

clean:
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean: clean
	rm -f $(NAME)
	rm -f my_ls
	rm -f my_sokoban

re:	fclean all

unit_tests: 	fclean $(OBJ)
	gcc -o unit_tests $(OBJ) tests/test_my_printf.c --coverage -lcriterion

tests_run:	unit_tests
	./unit_tests
