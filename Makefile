##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		fill_tab.c	\
				main.c
				
NAME	=		bsq

$(NAME):
		gcc -o $(NAME) $(SRC) -g

all: $(NAME)

clean:	
		rm -f $(NAME)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
