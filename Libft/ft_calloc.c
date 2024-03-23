/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:08:13 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/20 17:31:14 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = num * size;
	dst = malloc(tot_size);
	if (!dst)
		return (0);
	ft_bzero(dst, tot_size);
	return (dst);
}
/*
int main() 
{
    int *arr;
    int i;

	i = 0;
    arr = ft_calloc(5, sizeof(int));
    if (arr == NULL) {
        printf("Failed to allocate memory\n");
        return (1);
    }
    while (i < 5) 
	{
        printf("%d ", arr[i]);
		i++;
    }
    printf("\n");
    free(arr);

    return (0);
}
*/
