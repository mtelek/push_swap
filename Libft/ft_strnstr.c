/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:38:12 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/11 18:56:46 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	h;

	n = 0;
	h = 0;
	if (needle[n] == 0)
		return ((char *)(haystack));
	while (haystack[h] != '\0' && h < len)
	{
		n = 0;
		while (haystack[h + n] == needle[n] && (h + n) < len)
		{
			if (needle[n + 1] == '\0')
				return ((char *)(haystack + h));
			n++;
		}
		h++;
	}
	return (0);
}
/*
int main(void)
{
    const char *haystack = "Hello World";
    const char *needle = "Hello";
    size_t len = 16;

    char *result = ft_strnstr(haystack, needle, len);
    if (result != NULL)
    {
        printf("Needle found at position %ld: %s\n", result - haystack, result);
    }
	else
	{
		printf("Needle not found.\n");
	}
    return (0);
}
*/
