/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:31:30 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/13 15:31:30 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "./Libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	int				value;
	int				current_position;
	int				final_index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void			sa(t_list **stack_a, bool checker);
void			sb(t_list **stack_b, bool checker);
void			ss(t_list **stack_a, t_list **stack_b);
void			pa(t_list **stack_a, t_list **stack_b);
void			pb(t_list **stack_a, t_list **stack_b);
void			ra(t_list **stack_a, bool checker);
void			rb(t_list **stack_b, bool checker);
void			rr(t_list **stack_a, t_list **stack_b);
void			rra(t_list **stack_a, bool checker);
void			rrb(t_list **stack_b, bool checker);
void			rrr(t_list **stack_a, t_list **stack_b);
void			three_elements(t_list **stack_a);
void			four_elements(t_list **stack_a, t_list **stack_b);
void			five_elements(t_list **stack_a, t_list **stack_b);
void			sorting_big(t_list **stack_a, t_list **stack_b);
int				maxvalfind(t_list **stack_a);
int				minvalfind(t_list **stack_a);
long long int	ft_atoll(const char *str);
int				checker(char **args);
int				checker_mini_max(char **args);
int				checker_double(char **args);
void			handle_error(void);
void			handle_failure(char **args);
void			free_list(t_list *stack);
void			free_args(char **args);
int				argc_maker(t_list **stack_a);
void			print_stack(t_list *stack, const char *text);

//FOR THE ALGORITHM
void			set_current_position(t_list *stack);
void			set_target_node(t_list *a, t_list *b);
void			set_price(t_list *a, t_list *b);
void			set_cheapest(t_list *b);
t_list			*return_cheapest(t_list *stack);
t_list			*find_smallest(t_list *stack);
int				stack_len(t_list *stack);
bool			stack_sorted(t_list *stack);
void			rotate_both(t_list **stack_a, t_list **stack_b,
					t_list *cheapest_node);
void			reverse_rotate_both(t_list **stack_a, t_list **stack_b,
					t_list *cheapest_node);

#endif