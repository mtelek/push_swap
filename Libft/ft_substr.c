/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:12:21 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/15 17:47:36 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*substr;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
int main(void) 
{
	 char *str = "Hello, world!";
    unsigned int start = 7;
    size_t len = 5;
    char *substr = ft_substr(str, start, len);

    printf("Original string: %s\n", str);
    printf("Substring: %s\n", substr);

    free(substr);

    return 0;
}
*/
