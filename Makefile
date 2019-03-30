# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 23:52:47 by tingo             #+#    #+#              #
#    Updated: 2019/03/30 09:33:09 by tingo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = gcc
CFLAGS = -Wall -Werror -Wextra -std=gnu11
NAME   = bin/minishell

SDIR   = src
ODIR   = obj
LDIR   = libft
IDIR   = includes

_SRC   = builtin_map.c \
				 launcher.c \
				 main.c \
				 minishell.c \
				 ms_env.c \
				 ms_getline.c \
				 ms_tokenize.c
SRC    = $(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ   = $(_SRC:.c=.o)
OBJ    = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: $(NAME)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(CFLAGS) -c $(SRC) -I $(IDIR)
	@mkdir -p $(ODIR) bin
	@mv $(_OBJ) $(ODIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(IDIR) -L $(LDIR) -lft

clean:
	@make clean -C libft
	@/bin/rm -rf $(ODIR)
	@echo remove $(ODIR)

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf bin
	@echo remove bin

re:	fclean all
