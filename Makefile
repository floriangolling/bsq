##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		src/bsq_part_one.c		\
				src/bsq_part_two.c		\
				src/bsq_part_three.c	\
				src/bsq_part_four.c		\
				src/main.c
				
NAME	=		bsq

$(NAME):
		gcc -o $(NAME) $(SRC) -g

all: $(NAME)

clean:	
		rm -f $(NAME)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
