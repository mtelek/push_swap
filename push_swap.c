/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:31:23 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/13 15:31:23 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argc_maker(t_list **stack_a)
{
	int		argc;
	t_list	*current;

	argc = 1;
	current = *stack_a;
	while (current != NULL)
	{
		current = current->next;
		argc++;
	}
	return (argc);
}

void	argc_check(t_list **stack_a, t_list **stack_b, int argc)
{
	if (stack_a)
	{
		if (argc == 3)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a, false);
		}
		else if (argc == 4)
			three_elements(stack_a);
		else if (argc == 5)
			four_elements(stack_a, stack_b);
		else if (argc == 6)
			five_elements(stack_a, stack_b);
		else if (argc > 6)
			sorting_big(stack_a, stack_b);
	}
}

void	stack_making(t_list **stack_a, t_list **stack_b, char **args, int i)
{
	t_list	*temp_a;
	t_list	*last;

	while (args[i])
	{
		temp_a = (t_list *)malloc(sizeof(t_list));
		if (!temp_a)
			handle_error("Error");
		temp_a->value = ft_atoi(args[i]);
		temp_a->next = NULL;
		if (*stack_a == NULL)
			*stack_a = temp_a;
		else
		{
			last = *stack_a;
			while (last->next != NULL)
				last = last->next;
			last->next = temp_a;
			temp_a->prev = last;
		}
		i++;
	}
	*stack_b = NULL;
}

char	**getting_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			handle_error("Error");
	}
	else
		args = argv;
	return (args);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		counter;

	stack_a = NULL;
	counter = 1;
	if (argc >= 2)
	{
		args = getting_args(argc, argv);
		if (argc == 2)
			counter = 0;
		if (checker(args) || checker_mini_max(args) || checker_double(args))
			handle_error("Error");
		stack_making(&stack_a, &stack_b, args, counter);
		argc = argc_maker(&stack_a);
		if (!stack_sorted(stack_a))
			argc_check(&stack_a, &stack_b, argc);
		free_list(stack_a);
		free_list(stack_b);
		if (!counter)
			free_args(args);
	}
	return (0);
}
