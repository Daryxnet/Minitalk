/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:56 by dagarmil          #+#    #+#             */
/*   Updated: 2024/10/09 10:43:35 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return ((char *)&str[ft_strlen_gnl(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !buff)
		return (NULL);
	str = malloc(sizeof(char) * \
			((ft_strlen_gnl(s1) + ft_strlen_gnl(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_gnl(s1) + ft_strlen_gnl(buff)] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_line(char *static_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!static_str || !static_str[i])
		return (NULL);
	while (static_str[i] && static_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (static_str[i] && static_str[i] != '\n')
	{
		str[i] = static_str[i];
		i++;
	}
	if (static_str[i] == '\n')
	{
		str[i] = static_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_static_str(char *static_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (!static_str[i])
	{
		free(static_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(static_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (static_str[i])
		str[j++] = static_str[i++];
	str[j] = '\0';
	free(static_str);
	return (str);
}
