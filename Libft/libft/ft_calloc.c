/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:10:01 by dagarmil          #+#    #+#             */
/*   Updated: 2024/06/28 13:24:07 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pnt;

	pnt = (void *)malloc(nmemb * size);
	if (!pnt)
		return (NULL);
	ft_memset(pnt, '1', 8);
	ft_bzero(pnt, (nmemb * size));
	return (pnt);
}
