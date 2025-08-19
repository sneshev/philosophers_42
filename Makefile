NAME := philo

SRCS := $(shell find src -name "*.c")

OBJS := $(patsubst src/%.c, obj/%.o, $(SRCS))

CC := cc -g

CFLAGS := -Wall -Werror -Wextra

RM := rm -rf

all: obj $(NAME)

obj:
	mkdir -p obj

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)
	$(RM) obj

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re