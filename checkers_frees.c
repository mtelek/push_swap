/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_frees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:30:49 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/13 15:30:49 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *stack)
{
	t_list	*next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	checker(char **args)
{
	int	n;
	int	i;

	n = 1;
	while (args[n])
	{
		i = 0;
		while (args[n] && args[n][i])
		{
			if ((args[n][i] == '+' || args[n][i] == '-') &&
				(args[n][i + 1] == '+' || args[n][i + 1] == '-'))
				return (1);
			if ((args[n][i] < '0' || args[n][i] > '9') &&
			(args[n][i] != ' ' && args[n][i] != '-' && args[n][i] != '+'))
				return (1);
			i++;
		}
		n++;
	}
	return (0);
}

int	checker_double(char **args)
{
	int	n;
	int	currentnumber;
	int	j;

	n = 1;
	while (args[n])
	{
		currentnumber = ft_atoi(args[n]);
		j = n - 1;
		while (j > 0)
		{
			if (currentnumber == ft_atoi(args[j]))
				return (1);
			j--;
		}
		n++;
	}
	return (0);
}

int	checker_mini_max(char **args)
{
	int				n;
	long long int	num;

	n = 1;
	while (args[n])
	{
		num = ft_atoll(args[n]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		n++;
	}
	return (0);
}
