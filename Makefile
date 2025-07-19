NAME = push_swap
CC = cc
ifneq ($(CI),)
    CFLAGS = -Wall -Wextra -Werror -g
    LDFLAGS = 
else
    CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
    LDFLAGS = -fsanitize=address
endif
SRCDIR = .
OBJDIR = .objs
SRCS = checkers_frees.c min_max_find.c push_swap.c reverse_rotate.c rotate.c \
       sort_utils.c sort_utils2.c sort_elements.c sorting_big.c switch_push.c utils.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
LIBFTPRINTF = ft_printf/libftprintf.a
LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) $(LIBFT) -o $(NAME) $(LDFLAGS)
	@echo "\033[32m✓ Push_swap compiled successfully\033[0m"

$(LIBFTPRINTF):
	@make -C ft_printf --no-print-directory >/dev/null 2>&1
	@echo "\033[32m✓ ft_printf library compiled\033[0m"

$(LIBFT):
	@make -C Libft --no-print-directory >/dev/null 2>&1
	@echo "\033[32m✓ libft library compiled\033[0m"

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@) >/dev/null 2>&1
	@$(CC) $(CFLAGS) -c $< -o $@ >/dev/null 2>&1

$(OBJDIR):
	@mkdir -p $(OBJDIR) >/dev/null 2>&1
	@echo "\033[32m✓ Created objects directory\033[0m"

clean:
	@rm -f $(OBJS) >/dev/null 2>&1
	@rm -rf $(OBJDIR) >/dev/null 2>&1
	@make -C ft_printf clean --no-print-directory >/dev/null 2>&1
	@make -C Libft clean --no-print-directory >/dev/null 2>&1
	@echo "\033[32m✓ Cleaned all object files\033[0m"

fclean: clean
	@rm -f $(NAME) >/dev/null 2>&1
	@make -C ft_printf fclean --no-print-directory >/dev/null 2>&1
	@make -C Libft fclean --no-print-directory >/dev/null 2>&1
	@echo "\033[32m✓ Full clean completed\033[0m"

re: fclean all
	@echo "\033[32m✓ Rebuild completed\033[0m"
