/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecmarti <hecmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:45:40 by hecmarti          #+#    #+#             */
/*   Updated: 2024/04/15 12:57:10 by hecmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Frees the memory allocated for the buffer.
 * 
 * This function frees the memory allocated for the buffer and returns NULL.
 * 
 * @param buffer The buffer to be freed.
 * @return NULL
 */
char	*ft_bufffree(char *buffer)
{
	free (buffer);
	return (NULL);
}

/**
 * Frees the memory allocated for a line.
 * 
 * @param line The line to be freed.
 * @return NULL.
 */
char	*ft_linefree(char *line)
{
	free (line);
	return (NULL);
}

/**
 * @brief Reads the next line from a file descriptor.
 *
 * This function reads the next line from the file descriptor specified by `fd`.
 * It uses a static variable `full` to store the remaining characters from previous reads.
 * The function reads `BUFFER_SIZE` bytes at a time into a buffer, and appends it to `full`.
 * It continues reading until it encounters a newline character or reaches the end of the file.
 * The function then extracts the line from `full`, updates `full` to store the remaining characters,
 * and returns the extracted line.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the next line read from the file descriptor, or NULL if an error occurs or the end of file is reached.
 */
char	*get_next_line(int fd)
{
	int			bytes;
	char		*buffer;
	static char	*full;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(full, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		if (bytes < 0)
			return (ft_bufffree (buffer));
		full = ft_strjoin(full, buffer);
	}
	free(buffer);
	line = ft_linejoin(full);
	full = ft_substr(full, ft_slen(full, '\n') + 1, ft_slen(full, 0));
	if (!bytes && *line == '\0')
		return (ft_linefree(line));
	return (line);
}
