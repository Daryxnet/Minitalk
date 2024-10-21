/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:52:44 by dagarmil          #+#    #+#             */
/*   Updated: 2024/08/01 12:33:38 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char format)
{
	int	size;

	size = 0;
	if (format == 'c')
		size += ft_printchar(va_arg(args, int));
	else if (format == 's')
		size += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		size += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		size += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		size += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		size += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		size += ft_printpercent();
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			size += 1;
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (size);
}
