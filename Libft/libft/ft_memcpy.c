/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:07:28 by dagarmil          #+#    #+#             */
/*   Updated: 2024/09/26 18:58:38 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}*/
/*
int	main(int ac, char **av)
{
	int	i;
	char	*buff;

	i = 2;
	while (i < ac)
	{
		buff = ft_memcpy(av[1], av[2], 5);
		printf("%s\n", buff);
		i++;
	}
	return 0;
}*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
