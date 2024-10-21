/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:36:33 by dagarmil          #+#    #+#             */
/*   Updated: 2024/10/09 10:38:15 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_static_str(int fd, char *static_str);
size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *str, int c);
char	*ft_strjoin_gnl(char *s1, char *buff);
char	*ft_get_line(char *static_str);
char	*ft_new_static_str(char *static_str);

#endif
