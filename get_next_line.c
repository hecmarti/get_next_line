/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecmarti <hecmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:45:40 by hecmarti          #+#    #+#             */
/*   Updated: 2024/04/25 16:03:07 by hecmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Frees the memory allocated for a line.
 * 
 * @param line The line to be freed.
 * @return NULL.
 */
char	*linefree(char *line)
{
	free (line);
	return (NULL);
}

/**
 * @brief Reads the next line from a file descriptor
 * specified by `fd`. It uses a static variable `rchars` to store
 * the remaining characters from previous reads. The function
 * reads `BUFFER_SIZE` bytes at a time into a buffer, and appends it to `rchars`.
 * It continues reading until it encounters a newline character or reaches
 * the end of the file. The function then extracts the line from `rchars`,
 * updates `rchars` to store the remaining characters,
 * and returns the extracted line.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the next line read from the file descriptor,
 * or NULL if an error occurs or the end of file is reached.
 */
char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*read_buffer;
	static char	*rchars = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(rchars, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0) {
		ft_bzero(rchars, ft_slen(rchars, '\0'));
			return ( free(read_buffer), NULL);
	}
		read_buffer[bytes_read] = '\0';
		rchars = ft_strjoin(rchars, read_buffer);
	}
	linefree(read_buffer);
	line = ft_linejoin(rchars);
	rchars = ft_substr(rchars, ft_slen(rchars, '\n') + 1, ft_slen(rchars, 0));
	if (!bytes_read && *line == '\0')
		return (free(line), NULL);
	return (line);
}
