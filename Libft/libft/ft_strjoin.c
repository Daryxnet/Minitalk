/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:48:56 by dagarmil          #+#    #+#             */
/*   Updated: 2024/06/28 19:07:18 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	while (s1[++i])
		newstr[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		newstr[len1] = s2[i];
		len1++;
	}
	newstr[len1] = '\0';
	return (newstr);
}
/*
int	main(int ac, char **av)
{
	char	*new;

	new = ft_strjoin(av[1], av[2]);
	printf("la nueva string es: %s\n", new);
	free(new);
	return (0);
}*/
