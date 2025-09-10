NAME := philo

SRCS := src/main.c \
	src/valid_and_init/forks.c src/valid_and_init/philos.c src/valid_and_init/validate_input_messages.c src/valid_and_init/validate_input.c \
	src/utils/helpers.c src/utils/time.c src/utils/utils.c \
	src/dinner/eat.c src/dinner/monitor.c src/dinner/routine.c src/dinner/sleeep.c src/dinner/think.c src/dinner/utils.c

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