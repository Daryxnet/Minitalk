/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:10:35 by dagarmil          #+#    #+#             */
/*   Updated: 2024/09/26 19:07:25 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*
static int	count_words(char const *s, char c)
{
	int	cw;

	cw = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			cw++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	cw++;
	return (cw);
}

static void	*ft_free(char **memo, size_t buff)
{
	size_t	i;

	i = 0;
	while (i < buff)
	{
		free(memo[i]);
		i++;
	}
	free(memo);
	return (NULL);
}

static void	ft_armk(char **array, char *nstr, char c, int cws)
{
	int		i;
	char	*strchr;

	i = 0;
	if ((cws > 0) && *nstr)
	{
		while (i < (cws - 1))
		{
			strchr = ft_strchr(nstr, c);
			array[i++] = ft_substr(nstr, 0, strchr - nstr);
			if (array == 0)
			{
				ft_free(array, i);
				return ;
			}
			while (*strchr == c)
				strchr++;
			nstr = strchr;
		}
		array[i++] = ft_strdup(nstr);
		array[i] = 0;
	}
}

char	**ft_split(char const *s, char c)
{
	int		cws;
	char	**array;
	char	*nstr;
	char	corn[2];

	corn[0] = c;
	corn[1] = '\0';
	if (s)
	{
		nstr = ft_strtrim(s, corn);
		if (nstr)
		{
			cws = count_words(nstr, c);
			array = ft_calloc((cws + 1), sizeof(char *));
			if (array)
				ft_armk(array, nstr, c, cws);
			free(nstr);
			return (array);
		}
	}
	return (0);
}*/
/*
#include <stdio.h>

int	main()
{
	char	*str;
	char	**narray;
	char	x;
	int		i;

	x = ' ';
	i = 0;
	str = "      Ho la Co mo Es tas   ";
	narray = ft_split(str, x);
	while (narray[i])
	{
		printf("strings resultantes: %s\n", narray[i]);
		i++;
	}
	free(narray);
	return (0);
}*/
