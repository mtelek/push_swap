/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:31:18 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/30 21:05:07 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, bool checker)
{
	t_list	*head;
	t_list	*next;
	int		temp_value;

	head = *stack_a;
	if (head == NULL || head->next == NULL)
		return ;
	next = head->next;
	temp_value = head->value;
	head->value = next->value;
	next->value = temp_value;
	if (!checker)
		ft_printf("sa\n");
}

void	sb(t_list **stack_b, bool checker)
{
	t_list	*head;
	t_list	*next;
	int		temp_value;

	head = *stack_b;
	if (head == NULL || head->next == NULL)
		return ;
	next = head->next;
	temp_value = head->value;
	head->value = next->value;
	next->value = temp_value;
	if (!checker)
		ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, true);
	sb(stack_b, true);
	ft_printf("ss\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*temp;

	if (*stack_b)
	{
		head_a = *stack_a;
		head_b = *stack_b;
		if (head_b == NULL)
			return ;
		temp = malloc(sizeof(t_list));
		if (!temp)
			handle_error();
		temp->value = head_b->value;
		temp->cheapest = false;
		temp->next = head_a;
		*stack_a = temp;
		*stack_b = head_b->next;
		free(head_b);
		ft_printf("pa\n");
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*temp;

	if (*stack_a)
	{
		head_a = *stack_a;
		head_b = *stack_b;
		if (head_a == NULL)
			return ;
		temp = malloc(sizeof(t_list));
		if (!temp)
			handle_error();
		temp->value = head_a->value;
		temp->cheapest = false;
		temp->next = head_b;
		*stack_b = temp;
		*stack_a = head_a->next;
		free(head_a);
		ft_printf("pb\n");
	}
}
