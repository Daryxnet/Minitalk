/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:55:15 by dagarmil          #+#    #+#             */
/*   Updated: 2024/08/01 12:26:36 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_printunsigned(unsigned int n);
int		ft_printchar(int c);
int		ft_printpercent(void);
int		ft_printhex(unsigned int num, const char format);

#endif
