/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:31:42 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/29 23:32:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
/*
int main(void)
{
    const char *source = "Hello, World!";
    char *duplicate = ft_strdup(source);

    if (duplicate != NULL)
    {
        printf("Original string: %s\n", source);
        printf("Duplicated string: %s\n", duplicate);
        free(duplicate);
    }

    return 0;
}
*/
