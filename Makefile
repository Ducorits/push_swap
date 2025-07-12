CC		=	gcc

ifeq ($(TESTFLAGS), 1)
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
else
CFLAGS	=	-Wall -Werror -Wextra
endif

SRCS	=	main.c \
			error_check.c \
			stack_utils.c \
			sort_utils.c \
			sorting/smaller_sort.c \
			sorting/index_sorting.c \
			sorting/hybrid_sort.c \
			sorting/hybrid_sort_utils.c \
			instructions/rotate.c \
			instructions/reverse_rotate.c \
			instructions/swap.c \
			instructions/push.c

OBJS	=	$(patsubst %.c, obj/%.o, $(SRCS))

NAME	=	push_swap

INC		=	-I ./include

LIBFT	=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $^ $(CFLAGS) $(INC) -o $@

obj/%.o: src/%.c include/push_swap.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	make -C libft/

clean:
	@rm -f *.o
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
