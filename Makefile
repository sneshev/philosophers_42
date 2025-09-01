NAME := philo

SRCS := $(shell find src -name "*.c")

OBJS := $(patsubst src/%.c, obj/%.o, $(SRCS))

CC := cc -g

CFLAGS := -Wall -Werror -Wextra

RM := rm -rf

all: $(NAME)

$(shell mkdir -p $(dir $(OBJS)))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) obj

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re