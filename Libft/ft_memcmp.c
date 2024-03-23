/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:28:19 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/10 23:36:50 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char *)ptr1)[i] != ((unsigned char *)ptr2)[i])
			return (((unsigned char *)ptr1)[i] - ((unsigned char *)ptr2)[i]);
		i++;
	}
	return (0);
}
/*
int main() 
{
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    int result;

    result = ft_memcmp(str1, str2, sizeof(str1));
    printf("Comparison result of str1 and str2: %d\n", result);

    result = ft_memcmp(str1, str3, sizeof(str1));
    printf("Comparison result of str1 and str3: %d\n", result);

    return 0;
}
*/
