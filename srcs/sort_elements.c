/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number_of_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:31:36 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/13 15:31:36 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elements(t_list **stack_a)
{
	int	maxval;

	maxval = maxvalfind(stack_a);
	if ((*stack_a) && (*stack_a)->next && (*stack_a)->next->next)
	{
		if (maxval == (*stack_a)->value)
		{
			ra(stack_a, false);
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a, false);
		}
		if (maxval == (*stack_a)->next->value)
		{
			rra(stack_a, false);
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a, false);
		}
		if (maxval == (*stack_a)->next->next->value)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a, false);
		}
	}
}

void	snippet_four(t_list **stack_a, t_list **stack_b, int maxval)
{
	if (maxval == (*stack_a)->value)
		pb(stack_a, stack_b);
	else if (maxval == (*stack_a)->next->value)
	{
		sa(stack_a, false);
		pb(stack_a, stack_b);
	}
	else if (maxval == (*stack_a)->next->next->value)
	{
		rra(stack_a, false);
		rra(stack_a, false);
		pb(stack_a, stack_b);
	}
	else if (maxval == (*stack_a)->next->next->next->value)
	{
		rra(stack_a, false);
		pb(stack_a, stack_b);
	}
}

void	four_elements(t_list **stack_a, t_list **stack_b)
{
	int	maxval;

	maxval = maxvalfind(stack_a);
	if ((*stack_a) && (*stack_a)->next && (*stack_a)->next->next)
	{
		if ((*stack_a)->next->next->next)
		{
			snippet_four(stack_a, stack_b, maxval);
			three_elements(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a, false);
		}
	}
}

void	snippet_five(t_list **stack_a, t_list **stack_b, int maxval)
{
	if (maxval == (*stack_a)->value)
		pb(stack_a, stack_b);
	else if (maxval == (*stack_a)->next->value)
	{
		sa(stack_a, false);
		pb(stack_a, stack_b);
	}
	else if (maxval == (*stack_a)->next->next->value)
	{
		ra(stack_a, false);
		ra(stack_a, false);
		pb(stack_a, stack_b);
	}
	else if (maxval == (*stack_a)->next->next->next->value)
	{
		rra(stack_a, false);
		rra(stack_a, false);
		pb(stack_a, stack_b);
	}
	else if (maxval == (*stack_a)->next->next->next->next->value)
	{
		rra(stack_a, false);
		pb(stack_a, stack_b);
	}
}

void	five_elements(t_list **stack_a, t_list **stack_b)
{
	int	maxval;

	maxval = maxvalfind(stack_a);
	if ((*stack_a) && (*stack_a)->next && (*stack_a)->next->next)
	{
		if ((*stack_a)->next->next->next && (*stack_a)->next->next->next->next)
		{
			snippet_five(stack_a, stack_b, maxval);
			four_elements(stack_a, stack_b);
			pa(stack_a, stack_b);
			ra(stack_a, false);
		}
	}
}
