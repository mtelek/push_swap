/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:10:17 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/13 18:16:00 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	h;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	h = 0;
	while (src[h] != '\0' && (i + 1 < size))
	{
		dst[i] = src[h];
		i++;
		h++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[h]));
}
/*
int main() 
{
    char dst[20] = "Hello, ";
    const char *src = "world!";
    size_t result = ft_strlcat(dst, src, sizeof(dst));

    printf("Concatenated string: %s\n", dst);
    printf("Result: %zu\n", result);

    return 0;
}
*/
