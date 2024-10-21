/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:18:24 by dagarmil          #+#    #+#             */
/*   Updated: 2024/07/31 12:23:55 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int		size;
	char	*num;

	size = 0;
	num = ft_itoa(n);
	size = ft_printstr(num);
	free(num);
	return (size);
}
