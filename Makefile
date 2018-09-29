# Makefile
# Erwan Dupard

CC = gcc

RM = rm -f

CFLAGS += -W -Wall -Werror -Wextra -pedantic -ansi

NAME = sniffer.out

LDFLAGS	+=

SRCSDIR = ./src
SRCS := $(shell find $(SRCSDIR) -name '*.c') 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re



