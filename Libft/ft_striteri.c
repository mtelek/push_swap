/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:51:37 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/16 20:15:29 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/*
void	print_index_and_character(unsigned int index, char *character)
{
	printf("Index: %u, Character: %c\n", index, *character);
}

int	main(void)
{
	char	str[] = "Hello, World!";

	ft_striteri(str, print_index_and_character);
	return (0);
}
*/
