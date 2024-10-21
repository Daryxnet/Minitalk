/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:09:41 by dagarmil          #+#    #+#             */
/*   Updated: 2024/07/10 17:16:56 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	char	*s;
	size_t	res;

	s = (char *)src;
	dstlen = ft_strlen(dest);
	srclen = ft_strlen(s);
	i = 0;
	res = 0;
	if (size > dstlen)
		res = srclen + dstlen;
	else
		res = srclen + size;
	while (s[i] && (dstlen + 1) < size)
	{
		dest[dstlen] = s[i];
		i++;
		dstlen++;
	}
	dest[dstlen] = '\0';
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	char 	*dest;
	char 	*src;
	size_t	size;
	size_t	newsize;

	dest = "a";
	src = "lorem";
	size = 3;
	newsize = ft_strlcat(dest, src, size);
	printf("mi nuevo len es %zu\n", newsize);
	printf("mi str es: %s\n", src);
	printf("mi dest  es: %s\n", dest);
	return (0);
}*/
