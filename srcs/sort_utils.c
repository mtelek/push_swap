/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:42:48 by marvin            #+#    #+#             */
/*   Updated: 2024/03/22 23:42:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_smallest(t_list *stack)
{
	long			smallest;
	t_list			*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	set_current_position(t_list *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (!stack)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_match_index;

	while (stack_b != NULL)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a != NULL)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			stack_b->target_node = find_smallest(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	set_price(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b != NULL)
	{
		stack_b->push_price = stack_b->current_position;
		if (!(stack_b->above_median))
			stack_b->push_price = len_b - (stack_b->current_position);
		if (stack_b->target_node->above_median)
			stack_b->push_price += stack_b->target_node->current_position;
		else
			stack_b->push_price += len_a
				- (stack_b->target_node->current_position);
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_list *stack_b)
{
	long			best_match_value;
	t_list			*best_match_node;

	if (!stack_b)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b != NULL)
	{
		if (stack_b->push_price < best_match_value)
		{
			best_match_value = stack_b->push_price;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_match_node->cheapest = true;
}
