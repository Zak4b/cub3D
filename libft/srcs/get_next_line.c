/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:24:40 by asene             #+#    #+#             */
/*   Updated: 2024/12/25 20:22:01 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "get_next_line.h"

static char	*ft_join_and_free(char **s1, char const *s2)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while ((*s1)[i])
	{
		new_str[i] = (*s1)[i];
		i++;
	}
	while (*s2)
		new_str[i++] = *(s2++);
	new_str[i] = '\0';
	free(*s1);
	return (new_str);
}

static void	move_buffer(char **buffer, size_t eol_index)
{
	char	*temp;

	temp = *buffer;
	*buffer = ft_strdup(*buffer + eol_index + 1);
	free(temp);
}

static size_t	read_file_to_next_line(int fd, char **stash)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*eol;

	eol = ft_strchr(*stash, '\n');
	while (eol == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (stash && *stash)
			*stash = ft_join_and_free(stash, buffer);
		else
			*stash = ft_strdup(buffer);
		eol = ft_strchr(*stash, '\n');
	}
	if (bytes_read == 0)
		eol = *stash + ft_strlen(*stash) - 1;
	return (eol - *stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	int			eol;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	eol = read_file_to_next_line(fd, &stash);
	if (eol >= 0)
	{
		line = ft_substr(stash, 0, eol + 1);
		move_buffer(&stash, eol);
		return (line);
	}
	else
		return (free(stash), stash = NULL, NULL);
}
