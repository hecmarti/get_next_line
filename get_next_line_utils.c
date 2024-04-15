/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecmarti <hecmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:45:08 by hecmarti          #+#    #+#             */
/*   Updated: 2024/04/15 14:13:46 by hecmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Calculates the length of a string until a specified character is found.
 *
 * @param string The string to calculate the length of.
 * @param c The character to search for.
 * @return The length of the string until the specified character is found.
 */
int	ft_slen(char *string, char c)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == c)
			return (i);
		i++;
	}
	return (i);
}

/**
 * @brief Concatenates two strings together.
 *
 * @param full The first string.
 * @param buffer The second string.
 * @return The concatenated string.
 */
char	*ft_strjoin(char *full, char *buffer)
{
	char	*s;
	int		i;
	int		j;

	if (!full)
	{
		full = malloc(1);
		*full = '\0';
	}
	s = (char *)malloc(ft_slen(full, 0) + ft_slen(buffer, 0) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (full[i])
	{
		s[i] = full[i];
		i++;
	}
	while (buffer[j])
		s[i++] = buffer[j++];
	free (full);
	s[i] = '\0';
	return (s);
}

/**
 * @brief Extracts a line from a string.
 *
 * @param full The string to extract the line from.
 * @return The extracted line.
 */
char	*ft_linejoin(char *full)
{
	char	*s;
	int		i;
	int		j;

	j = ft_slen(full, '\n');
	if (!full)
		return (NULL);
	s = (char *)malloc(j + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (i < j + 1)
	{
		s[i] = full[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * @brief Extracts a substring from a string.
 *
 * @param full The string to extract the substring from.
 * @param start The starting index of the substring.
 * @param len The length of the substring.
 * @return The extracted substring.
 */
char	*ft_substr(char *full, int start, int len)
{
	char	*s;
	int		i;
	int		j;

	if (!ft_strchr(full, '\n'))
	{
		free(full);
		return (NULL);
	}
	s = (char *)malloc((len - start + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < start)
		i++;
	while (i < len)
		s[j++] = full[i++];
	s[j] = '\0';
	free (full);
	return (s);
}

/**
 * @brief Searches for the first occurrence of a character in a string.
 *
 * @param full The string to search in.
 * @param c The character to search for.
 * @return A pointer to the first occurrence of the character in the string,
 * or NULL if not found.
 */
char	*ft_strchr(char *full, char c)
{
	int	i;

	if (!full)
		return (NULL);
	i = 0;
	while (full[i])
	{
		if (full[i] == c)
			return (full + i);
		i++;
	}
	return (NULL);
}
