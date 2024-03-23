/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:56:09 by mtelek            #+#    #+#             */
/*   Updated: 2023/09/16 21:00:42 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	if (s[i] != '\0')
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
		write(fd, "\n", 1);
	}
}


int main(void)
{
        char *str = "Hello, World!";
        int fd = 1;

        ft_putstr(str, fd);
        return (0);
}
*/
