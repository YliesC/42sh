##
## Makefile for libmy in /home/chahi_y/lib/libmy
## 
## Made by chahi
## Login   <chahi_y@epitech.net>
## 
## Started on  Tue Dec  3 18:14:08 2013 chahi
## Last update Sun May 25 16:58:13 2014 chahi
##

INCDIR	= ./include/

SRC	= my_getnbr.c\
	my_power_rec.c\
	my_putchar.c\
	my_putstr.c\
	my_strdup.c\
	my_strlen.c\
	my_strncat.c\
	totab.c\
	epure_str.c\
	count_word.c\
	match.c\
	get_next_line.c\
	tronque.c\
	syscall.c\
	free_tab.c\

OBJ	= $(SRC:.c=.o)

NAME	= libmy.a

RM	= rm -f

CFLAGS	= -I $(INCDIR)

ifeq ($(DEBUG), yes)
	CFLAGS	+= -W -Wall -Wextra -g3
endif

LDFLAGS	= -L include -lmy

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
