/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:21:03 by iullibar          #+#    #+#             */
/*   Updated: 2025/10/02 11:23:22 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *save)
{
	char	buffer[BUFFER_SIZE + 1];
	int		r;

	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = '\0';
		save = ft_strjoin(save, buffer);
		if (!save || ft_strchr(save, '\n'))
			break ;
	}
	if (r <= 0 && (!save || !*save))
		return (free(save), NULL);
	return (save);
}

char	*get_line(char **save)
{
	int		i;
	char	*line;
	char	*rest;

	i = 0;
	if (!*save || !**save)
		return (NULL);
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	line = ft_substr(*save, 0, i + ((*save)[i] == '\n'));
	if (!(*save)[i])
	{
		free(*save);
		*save = NULL;
	}
	else
	{
		rest = ft_substr(*save, i + 1, ft_strlen(*save) - i - 1);
		free(*save);
		*save = rest;
	}
	return (line);
}
