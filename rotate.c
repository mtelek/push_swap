/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:31:13 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/13 15:31:13 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last_node(t_list *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ra(t_list **stack_a, bool checker)
{
	t_list			*last_node;
	int				len;

	len = stack_len(*stack_a);
	if (NULL == stack_a || NULL == *stack_a || 1 == len)
		return ;
	last_node = find_last_node(*stack_a);
	last_node->next = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (!checker)
		ft_printf("ra\n");
}

void	rb(t_list **stack_b, bool checker)
{
	t_list			*last_node;
	int				len;

	len = stack_len(*stack_b);
	if (NULL == stack_b || NULL == *stack_b || 1 == len)
		return ;
	last_node = find_last_node(*stack_b);
	last_node->next = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (!checker)
		ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, true);
	rb(stack_b, true);
	ft_printf("rr\n");
}
