SRCDIR	=	./srcs/

INCDIR	=	./includes/

LIBDIR	=	./lib/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)main_loop.c \
		$(SRCDIR)init_struct.c \

SRC	+=	$(SRCDIR)preprocess/clear_command.c \
		$(SRCDIR)preprocess/gest_error_cmd.c \
		$(SRCDIR)preprocess/misc.c \

SRC	+=	$(SRCDIR)builtin/builtin.c \
		$(SRCDIR)builtin/cd.c \
		$(SRCDIR)builtin/echo/echo.c \
		$(SRCDIR)builtin/echo/echo_options.c \

SRC	+=	$(SRCDIR)environment/check_env.c \
		$(SRCDIR)environment/env.c \
		$(SRCDIR)environment/fill_env.c \
		$(SRCDIR)environment/setenv.c \
		$(SRCDIR)environment/unsetenv.c \
		$(SRCDIR)environment/gest_env.c \

SRC	+=	$(SRCDIR)history/history.c \
		$(SRCDIR)history/gest_history.c \

SRC	+=	$(SRCDIR)alias/alias.c \
		$(SRCDIR)alias/unalias.c \
		$(SRCDIR)alias/gest_alias.c \

SRC	+=	$(SRCDIR)liste_gest/free_struct.c \
		$(SRCDIR)liste_gest/add_to_list.c \
		$(SRCDIR)liste_gest/print_liste.c \

SRC	+=	$(SRCDIR)misc/misc.c \
		$(SRCDIR)misc/utils.c \

SRC	+=	$(SRCDIR)exec/and_or.c \
		$(SRCDIR)exec/make_token.c \
		$(SRCDIR)exec/execute.c \
		$(SRCDIR)exec/func.c \
		$(SRCDIR)exec/parse.c \
		$(SRCDIR)exec/dlred.c \
		$(SRCDIR)exec/make_redir.c \
		$(SRCDIR)exec/mult_red.c \
		$(SRCDIR)exec/pipes.c \
		$(SRCDIR)exec/redirs.c \
		$(SRCDIR)exec/my_exit.c \
		$(SRCDIR)exec/signals.c \

SRC	+=	$(SRCDIR)readline/check_termcaps.c \
		$(SRCDIR)readline/my_readline.c \
	  	$(SRCDIR)readline/pool_functions.c \
	  	$(SRCDIR)readline/cursor.c \
	  	$(SRCDIR)readline/cursor_bis.c \
	  	$(SRCDIR)readline/init_data.c \
	  	$(SRCDIR)readline/empty.c \
	  	$(SRCDIR)readline/termcaps.c \
	  	$(SRCDIR)readline/cursor_history.c \
	  	$(SRCDIR)readline/check_two.c \

NAME	=	42sh

CC	=	gcc

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

LDFLAG	=	-L $(LIBDIR) -lmy -I $(LIBDIR)include -I $(INCDIR) -lncurses

CFLAGS	=	-I $(LIBDIR)include -I $(INCDIR) -W -Wall -Wextra -O3

ifeq ($(DEBUG), yes)
	CFLAGS	+= -og3
endif

all: lib $(NAME)

lib:
	make -C $(LIBDIR)

libre:
	make re -C $(LIBDIR)

libclean:
	make clean -C $(LIBDIR)

libfclean:
	make fclean -C $(LIBDIR)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAG)

clean: libclean
	$(RM) $(OBJ)

fclean: libfclean clean
	$(RM) $(NAME)

re: fclean all

.PHONY: lib all re
