CC        = gcc
CFLAGS    = -MMD -g3
CERR      = -Wall -Wextra
CERR     += -Werror
NAME      = minishell
BIN_DIR   = bin
BUILD_DIR = build

INC     = -Iincludes -Ilibft/includes
LIBS    = -Llibft -lft

SRC		= $(wildcard src/*.c)
OBJ		= $(SRC:%.c=$(BUILD_DIR)/%.o)
DEP		= $(OBJ:%.o=%.d)

all: $(NAME)

$(NAME): $(BIN_DIR)/$(NAME)

%/:
	mkdir -p $@

libft/libft.a:
	make -C libft

$(BIN_DIR)/$(NAME): $(OBJ) libft/libft.a | $(BIN_DIR)/
	$(CC) -o $@ $^ $(LIBS)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)/src/
	$(CC) $(CERR) $(CFLAGS) -c -o $@ $< $(INC)

-include $(DEP)

.PHONY: clean fclean re

clean:
	make -C libft clean
	rm -f $(OBJ)
	rm -f $(DEP)

fclean:
	make -C libft fclean
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

re: fclean all
