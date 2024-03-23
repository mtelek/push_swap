/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/19 17:28:14 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/19 17:28:14 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	init_nodes(t_list *stack_a, t_list *stack_b)
{
	set_current_position(stack_a);
	set_current_position(stack_b);
	set_target_node(stack_a, stack_b);
	set_price(stack_a, stack_b);
	set_cheapest(stack_b);
}

static void	move_nodes(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = return_cheapest(*stack_b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	finish_rotation(stack_b, cheapest_node, 'b');
	finish_rotation(stack_a, cheapest_node->target_node, 'a');
	pa(stack_a, stack_b);
}

void	sorting_big(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;
	int		length_a;

	if (!stack_sorted(*stack_a))
	{
		length_a = stack_len(*stack_a);
		while (length_a-- > 3)
			pb(stack_a, stack_b);
		three_elements(stack_a);
		while (*stack_b)
		{
			init_nodes(*stack_a, *stack_b);
			move_nodes(stack_a, stack_b);
		}
		set_current_position(*stack_a);
		smallest = find_smallest(*stack_a);
		if (smallest->above_median)
			while (*stack_a != smallest)
				ra(stack_a, false);
		else
			while (*stack_a != smallest)
				rra(stack_a, false);
	}
}
