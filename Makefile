NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = checkers_frees.c min_max_find.c push_swap.c reverse_rotate.c rotate.c sort_utils.c sort_utils2.c sort_elements.c sorting_big.c switch_push.c utils.c
OBJS = $(SRCS:.c=.o)
LIBFTPRINTF = ft_printf/libftprintf.a
LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) $(LIBFT) -o $(NAME)

$(LIBFTPRINTF):
	@make -C ft_printf

$(LIBFT):
	@make -C Libft

clean:
	@rm -f $(OBJS)
	@make -C ft_printf clean
	@make -C Libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ft_printf fclean
	@make -C Libft fclean
	
re: fclean all
