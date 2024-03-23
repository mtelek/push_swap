/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:03:23 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/07 23:53:36 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
/*
int main()
{
    const char *str = "Hi Barbie!";
    int c = 'i';
    char result = ft_strchr(str,c) - str + 1;

    if (result != 0)
    {
        printf("Character found at index: %d\n", result);
    }
    return 0;
}
*/