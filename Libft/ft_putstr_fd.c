/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:24:22 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/16 20:41:47 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s[i] != '\0')
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
/*
int	main(void)
{
		char *str = "Hello, World!";
		int fd = 1;

		ft_putstr(str, fd);
		return (0);
}
*/
