/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:27:55 by dagarmil          #+#    #+#             */
/*   Updated: 2024/07/10 19:08:46 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	l_len;
	char	*bc;

	i = 0;
	bc = (char *)big;
	l_len = ft_strlen(little);
	if (l_len == 0 || big == little)
		return (bc);
	while (bc[i] != '\0' && i < len)
	{
		l = 0;
		while (bc[i + l] && little[l]
			&& bc[i + l] == little[l] && (i + l) < len)
			l++;
		if (l == l_len)
			return (bc + i);
		i++;
	}
	return (NULL);
}
/*
{	
	size_t	b;
	size_t	l;

	b = 0;
	if (little[b] == '\0')
		return ((char *)big);
	while (big[b])
	{
		l = 0;
		while (big[b + l] == little[l] && (b + l) < len)
		{
			if (big[b + l] == '\0' && little[l] == '\0')
				return ((char *)big + b);
			l++;
		}
		b++;
	}
	return (NULL);
}*/
