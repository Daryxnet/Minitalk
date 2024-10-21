/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:54:37 by dagarmil          #+#    #+#             */
/*   Updated: 2024/07/11 16:01:16 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cn;

	cn = c;
	i = ft_strlen(s);
	if (cn == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == cn)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char	*str;
	char	*nstr;
	int		x;

	x = 'x';
	str = "HolaxComoxestas";
	nstr = ft_strrchr(str, x);
	printf("string result: %s\n", nstr);
	return 0;
}*/
