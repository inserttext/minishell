CC        = gcc
CFLAGS    = -MMD
CERR      = -Wall -Wextra -Werror
NAME      = minishell
BIN_DIR   = bin
BUILD_DIR = build

LIBS    = -Llibft -lft

SRC		= $(wildcard src/*.c)
OBJ		= $(SRC:%.c=$(BUILD_DIR)/%.o)
DEP		= $(OBJ:%.o=%.d)

all: $(NAME)

$(NAME): $(BIN_DIR)/$(NAME)

%/:
	mkdir -p $@

$(BIN_DIR)/$(NAME): $(OBJ) | $(BIN_DIR)/
	$(CC) -o $@ $^ $(LIBS)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)/src/
	$(CC) $(CERR) $(CFLAGS) -c -o $@ $< -I./includes -I./libft/includes

-include $(DEP)

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)
	rm -f $(DEP)

fclean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

re: fclean all
