/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:31:44 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/13 15:31:44 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_failure(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	handle_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	print_stack(t_list *stack, const char *text)
{
	ft_printf("%s: ", text);
	while (stack != NULL)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

long long int	parse_integer(const char *str, int sign)
{
	long long int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (result > LLONG_MAX / 10)
		{
			result = LLONG_MAX;
			break ;
		}
		if (result == LLONG_MAX / 10 && *str - '0' > LLONG_MAX % 10)
		{
			result = LLONG_MAX;
			break ;
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

long long int	ft_atoll(const char *str)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;
	if (str == NULL || *str == '\0')
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '+')
			sign = 1;
		else
			sign = -1;
		str++;
	}
	result = parse_integer(str, sign);
	return (result);
}
