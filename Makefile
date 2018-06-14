##
## Makefile for tekpaint in /home/morgan/rendu/gfx_tekpaint
##
## Made by Morgan Simon
## Login   <morgan@epitech.net>
##
## Started on  Tue Jan  5 14:27:45 2016 Morgan Simon
## Last update Wed Feb 17 18:49:42 2016 Morgan SIMON
##

NAME	=	tekpaint

CC	=	gcc

SRC	=	src/main.c		\
		src/tekpixel.c		\
		src/bmp.c		\
		src/set_data.c		\
		src/brush.c		\
		src/tekline_paint.c	\
		src/my.c		\
		src/button.c		\
		src/event.c		\
		src/tekline.c		\
		src/brush2.c		\
		src/my_ini.c		\
		src/my_getnbr.c		\
		src/get_next_line.c	\
		src/cp.c                \
		src/bmp_save.c          \
		src/get_click_event.c	\
		src/tekline_cir.c	\
		src/tekline_sqrt.c	\
		src/rev_array.c		\
		src/squares.c

LDFLAGS	=	-Lliblapin/ -llapin \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-lm

CFLAGS	+=	-W -Wall -O2
CFLAGS	+=	-Iliblapin/include/ -I./include

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

ECHO	=	/bin/echo -e


all:		lapin flag $(NAME)

lapin:
		@$(MAKE) -S -C liblapin/ -j4

flag:
		@$(ECHO) "\n\033[0;31mFLAGS : \033[00m" $(CFLAGS) "\n"

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) && \
		 cat res/ascii && \
		 $(ECHO) "\n\033[1;34m >> \033[0;32mCompiling DONE \033[1;34m<<\033[00m\n"

clean:
		@$(RM) $(OBJ)
		@$(MAKE) clean -S -C liblapin/
		@$(ECHO) "\033[0;32mClean OBJ Files\033[00m"

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) liblapin/liblapin.a
		@$(ECHO) "\033[0;32mClean Binary\033[00m"

re:		fclean all

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) "\033[0;32m ◉  »\033[1;34m" $< "\033[00m" || \
		 $(ECHO) "\033[0;31m ⊗  »\033[1;34m" $< "\033[00m"

.PHONY:		all clean fclean re
