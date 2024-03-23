/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:01:09 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/16 13:22:55 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		trimmed_len;
	char	*trimmed_str;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	trimmed_len = end - start + 1;
	trimmed_str = (char *)malloc(trimmed_len + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + start, trimmed_len + 1);
	return (trimmed_str);
}

/*
int main()
{
    char *s1 = "!!!!!Hello, World!!!!!";
    char *set = "!";

    char *trimmed_str = ft_strtrim(s1, set);
    printf("Original string: '%s'\n", s1);
    printf("Trimmed string: '%s'\n", trimmed_str);

    free(trimmed_str);

    return 0;
}
*/
