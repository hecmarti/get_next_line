/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecmarti <hecmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:45:40 by hecmarti          #+#    #+#             */
/*   Updated: 2024/04/25 17:09:56 by hecmarti         ###   ########.fr       */
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
 * specified by `fd`. It uses a static variable `r_ch` to store
 * the remaining characters from previous reads. The function
 * reads `BUFFER_SIZE` bytes at a time into a buffer, and appends it to `r_ch`.
 * It continues reading until it encounters a newline character or reaches
 * the end of the file. The function then extracts the line from `r_ch`,
 * updates `r_ch` to store the remaining characters,
 * and returns the extracted line.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the next line read from the file descriptor,
 * or NULL if an error occurs or the end of file is reached.
 */
char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*read_b;
	static char	*r_ch = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	read_b = malloc(BUFFER_SIZE + 1);
	if (!read_b)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(r_ch, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_b, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_bzero(r_ch, ft_slen(r_ch, '\0')), free(read_b), NULL);
		read_b[bytes_read] = '\0';
		r_ch = ft_strjoin(r_ch, read_b);
	}
	linefree(read_b);
	line = ft_linejoin(r_ch);
	r_ch = ft_substr(r_ch, ft_slen(r_ch, '\n') + 1, ft_slen(r_ch, 0));
	if (!bytes_read && *line == '\0')
		return (free(line), NULL);
	return (line);
}
