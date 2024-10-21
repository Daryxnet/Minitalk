/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:33:33 by dagarmil          #+#    #+#             */
/*   Updated: 2024/08/01 12:31:39 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cnt_udigit(unsigned int num)
{
	int	cnt;

	cnt = 0;
	while (num != 0)
	{
		cnt++;
		num = num / 10;
	}
	return (cnt);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		numlen;

	numlen = cnt_udigit(n);
	num = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!num)
		return (NULL);
	num[numlen] = '\0';
	while (n != 0)
	{
		num[numlen - 1] = (n % 10) + '0';
		n = n / 10;
		numlen--;
	}
	return (num);
}

int	ft_printunsigned(unsigned int n)
{
	int		size;
	char	*num;

	size = 0;
	if (n == 0)
		size += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		size += ft_printstr(num);
		free(num);
	}
	return (size);
}
