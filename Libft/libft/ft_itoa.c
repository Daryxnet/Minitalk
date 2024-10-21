/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:48:58 by dagarmil          #+#    #+#             */
/*   Updated: 2024/07/09 14:58:58 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>

static int	cnt_digt(int num)
{
	int	cnt;

	cnt = 0;
	if (num != 0)
	{
		if (num < 0)
		{
			num = num *(-1);
			cnt++;
		}
		while (num != 0)
		{
			num = num / 10;
			cnt++;
		}
	}
	else
		cnt = 1;
	return (cnt);
}

char	*ft_itoa(int n)
{
	int			numlen;
	char		*str;
	long int	num;

	num = n;
	numlen = cnt_digt(n);
	str = malloc(sizeof(char) * (numlen + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[numlen--] = '\0';
	while (num)
	{
		str[numlen] = (num % 10) + '0';
		num /= 10;
		numlen--;
	}
	return (str);
}
/*
int	main()
{
	int		num;
	char	*newstr;

	num = 115;
	i = 0;
	newstr = ft_itoa(num);
	printf("La str del numero %d es: %s\n", num, newstr);
	free(newstr);
	return (0);
}*/
