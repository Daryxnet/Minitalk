/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:11 by dagarmil          #+#    #+#             */
/*   Updated: 2024/10/09 10:40:22 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>

char	*ft_read_static_str(int fd, char *static_str)
{
	char	*buff;
	int		rt_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rt_bytes = 1;
	while (!ft_strchr_gnl(static_str, '\n') && rt_bytes != 0)
	{
		rt_bytes = read(fd, buff, BUFFER_SIZE);
		if (rt_bytes == -1)
		{
			free(static_str);
			free(buff);
			return (NULL);
		}
		buff[rt_bytes] = '\0';
		static_str = ft_strjoin_gnl(static_str, buff);
	}
	free(buff);
	return (static_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_str[fd] = ft_read_static_str(fd, static_str[fd]);
	if (!static_str[fd])
		return (NULL);
	line = ft_get_line(static_str[fd]);
	static_str[fd] = ft_new_static_str(static_str[fd]);
	return (line);
}
/*
int	main()
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("./test1.txt", O_RDONLY);
	fd2 = open("./test2.txt", O_RDONLY);
	fd3 = open("./test3.txt", O_RDONLY);
	i = 1;
	while (i < 6)
	{
		line = get_next_line(fd1);
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s\n", line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
