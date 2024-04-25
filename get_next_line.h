/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecmarti <hecmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:46:09 by hecmarti          #+#    #+#             */
/*   Updated: 2024/04/25 15:57:23 by hecmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *full, char *buffer);
int		ft_slen(char *string, char c);
char	*ft_linejoin(char *full);
char	*ft_substr(char *full, int start, int len);
char	*ft_strchr(char *full, char c);
char	*ft_linefree(char *line);
char	*ft_bufffree(char *buff);
void	ft_bzero(void *s, size_t n);
int     ft_lfc(char *str, char c);

#endif
