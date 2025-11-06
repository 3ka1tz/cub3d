/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:26:42 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/17 10:03:22 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	open_map_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Failed to open '%s' mapfile.\n", file);
		exit(1);
	}
	return (fd);
}

static char	**resize_map(char **map, int *capacity)
{
	char	**new_map;

	*capacity *= 2;
	new_map = realloc(map, sizeof(char *) * (*capacity));
	if (!new_map)
	{
		printf("Error: Realloc failed\n");
		exit(1);
	}
	return (new_map);
}

char	*modify_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	while (line[i])
	{
		if (line[i] >= 9 && line[i] <= 13)
			line[i] = ' ';
		i ++;
	}
	return (line);
}

char	**copy_file(int fd, int lines, int capacity)
{
	char	**map;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	map = malloc(sizeof(char *) * capacity);
	if (!map)
		exit(1);
	while (line)
	{
		if (check_line(line))
		{
			line = modify_line(line);
			if (lines >= capacity - 1)
				map = resize_map(map, &capacity);
			map[lines++] = line;
		}
		line = get_next_line(fd);
	}
	map[lines] = NULL;
	close(fd);
	return (map);
}

char	**extract_content(char *file)
{
	int		fd;
	char	**map;

	fd = open_map_file(file);
	map = copy_file(fd, 0, 8);
	if (!map)
	{
		printf("Error: Empty file\n");
		exit(1);
	}
	return (map);
}
