/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:31:08 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/13 15:31:08 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, bool checker)
{
	int		temp_value;
	t_list	*current;
	t_list	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	current = *stack_a;
	last = NULL;
	while (current != NULL && current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	temp_value = current->value;
	if (last != NULL)
		last->next = NULL;
	else
		*stack_a = NULL;
	current->next = *stack_a;
	current->value = temp_value;
	*stack_a = current;
	if (!checker)
		ft_printf("rra\n");
}

void	rrb(t_list **stack_b, bool checker)
{
	int		temp_value;
	t_list	*current;
	t_list	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	current = *stack_b;
	last = NULL;
	while (current != NULL && current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	temp_value = current->value;
	if (last != NULL)
		last->next = NULL;
	else
		*stack_b = NULL;
	current->next = *stack_b;
	current->value = temp_value;
	*stack_b = current;
	if (!checker)
		ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, true);
	rrb(stack_b, true);
	ft_printf("rrr\n");
}
