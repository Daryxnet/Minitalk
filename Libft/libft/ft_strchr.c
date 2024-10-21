/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:21:08 by dagarmil          #+#    #+#             */
/*   Updated: 2024/07/11 15:59:48 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cn;

	cn = c;
	while ((*s != '\0') && (*s != cn))
		s++;
	if (*s == cn)
		return ((char *)s);
	return (NULL);
}
/*
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}*/

/*
int	main()
{
	char	*str;
	char	*nstr;
	int		x;

	x = 'x';
	str = "HolaxComoxestas";
	nstr = ft_strchr(str, x);
	nstr++;
	printf("string resultante: %s\n", nstr);	
	return 0;
}*/
