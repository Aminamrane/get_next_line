# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include -DBUFFER_SIZE=42
SRCS = src/get_next_line.c src/utils.c main.c
OBJS = $(SRCS:.c=.o)
NAME = gnl

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all