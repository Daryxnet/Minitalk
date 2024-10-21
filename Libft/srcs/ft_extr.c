/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:35:20 by dagarmil          #+#    #+#             */
/*   Updated: 2024/07/31 14:40:26 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printpercent(void)
{
	write (1, "%", 1);
	return (1);
}
