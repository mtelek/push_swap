/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_valfind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:30:56 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/13 15:30:56 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxvalfind(t_list **stack_a)
{
	int		maxval;
	t_list	*current;

	maxval = (*stack_a)->value;
	current = (*stack_a)->next;
	while (current != NULL)
	{
		if (current->value > maxval)
			maxval = current->value;
		current = current->next;
	}
	return (maxval);
}

int	minvalfind(t_list **stack_a)
{
	int		minval;
	t_list	*current;

	minval = (*stack_a)->value;
	current = (*stack_a)->next;
	while (current != NULL)
	{
		if (current->value < minval)
			minval = current->value;
		current = current->next;
	}
	return (minval);
}
