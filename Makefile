##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC	=	main.c\
		collisions.c\
		verif.c

NAME	=	my_sokoban

LFLAGS	=	-L./lib

MFLAGS	=	-C./lib/my

IFLAGS	=	-I./include

NFLAGS	=	-lncurses

all:	$(NAME)

$(NAME):
	make $(MFLAGS)
	cc -o $(NAME) $(SRC) $(LFLAGS) -lmy $(IFLAGS) $(NFLAGS) -g

clean:
	rm -f $(NAME)

fclean:	clean
	make $(MFLAGS) clean

re:	fclean all
