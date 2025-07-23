NAME     = push_swap
CC       = cc

ifneq ($(CI),)
    CFLAGS  = -Wall -Wextra -Werror -g
    LDFLAGS = 
else
    CFLAGS  = -Wall -Wextra -Werror -g -fsanitize=address
    LDFLAGS = -fsanitize=address
endif

SRCS_DIR = srcs
OBJS_DIR = .objs
INCLUDES = -Iincludes

LIBFT     = Libft/libft.a
LIBFTPRINTF = ft_printf/libftprintf.a

SRCS = checkers_frees.c min_max_find.c push_swap.c reverse_rotate.c \
       rotate.c sort_utils.c sort_utils2.c sort_elements.c sorting_big.c \
       switch_push.c utils.c
OBJS = $(addprefix $(OBJS_DIR)/$(SRCS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFTPRINTF) -o $(NAME) $(LDFLAGS)
	@echo "\033[32m✓ $(NAME) compiled successfully\033[0m"

$(OBJS_DIR)/$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@make -C Libft --no-print-directory

$(LIBFTPRINTF):
	@make -C ft_printf --no-print-directory

clean:
	@rm -rf $(OBJS_DIR)
	@make -C Libft clean --no-print-directory
	@make -C ft_printf clean --no-print-directory
	@echo "\033[32m✓ Cleaned object files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C Libft fclean --no-print-directory
	@make -C ft_printf fclean --no-print-directory
	@echo "\033[32m✓ Full clean completed\033[0m"

re: fclean all
