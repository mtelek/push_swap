/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:25:39 by marvin            #+#    #+#             */
/*   Updated: 2024/03/23 13:25:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_list *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack != NULL)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

t_list	*return_cheapest(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node
		&& *stack_b != cheapest_node)
		rr(stack_a, stack_b);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b,
		t_list *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node
		&& *stack_b != cheapest_node)
		rrr(stack_a, stack_b);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}
