/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:57:17 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/20 17:30:31 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*ptr;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char )c)
		{
			ptr = str + i;
			return ((char *)ptr);
		}
		i--;
	}
	return (0);
}
/*
int	main(void)
{
    const char *str = "Hi Barbie!";
    int c = 'i';
    char result = ft_strrchr(str,c) - str + 1;

    if (result != 0)
    {
        printf("Character found at index: %d\n", result);
    }
    return 0;
}
*/
