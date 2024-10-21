/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:18:26 by dagarmil          #+#    #+#             */
/*   Updated: 2024/09/26 19:11:18 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*de;
	unsigned char	*sr;

	de = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (de >= sr)
	{
		while (n--)
			de[n] = sr[n];
	}
	else
		ft_memcpy(de, sr, n);
	return (dest);
}*/
