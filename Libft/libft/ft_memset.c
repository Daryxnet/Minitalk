/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:56:15 by dagarmil          #+#    #+#             */
/*   Updated: 2024/06/27 13:39:17 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*punt;
	size_t			i;

	i = 0;
	punt = s;
	while (i < n)
	{
		punt[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(int ac, char **av)
{
	int	i;
	char	*new;


	i = 1;
	while (i < ac)
	{
		new = ft_memset(av[1], 42, 5);
		printf("%s\n", new);	
		i++;
	}
	return 0;
}*/
