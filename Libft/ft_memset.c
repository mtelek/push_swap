/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:10:26 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/06 16:39:33 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)ptr)[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
	char allmemblock[4];
	void *ptr;
	int value;
	size_t len;

	value = 'B';
	len = 4;
	ptr = allmemblock;
	ft_memset(ptr, value, len);
	printf("%s\n",allmemblock);
	return (0);
}
*/
