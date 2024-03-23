/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:25:44 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/05 15:22:46 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((64 < c && c < 91) || (96 < c && c < 123))
		return (1);
	return (0);
}
/*
int main(void)
{
		int input;

		input = 'B';
		ft_isalpha(input);
		printf("%d", ft_isalpha(input));
		return (0);
}
*/
