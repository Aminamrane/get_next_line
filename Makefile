# Makefile

CC = clang
CFLAGS = -Wall -Wextra -Werror -I get_next_line/include -DBUFFER_SIZE=$(BUFFER_SIZE)
SRCS = get_next_line/src/get_next_line.c get_next_line/src/utils.c main.c
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