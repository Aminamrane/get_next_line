# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include -D BUFFER_SIZE=42

NAME = gnl

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/get_next_line.c $(SRC_DIR)/utils.c main.c
OBJS = $(SRCS:.c=.o)
OBJS := $(patsubst %.o,$(OBJ_DIR)/%.o,$(notdir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
