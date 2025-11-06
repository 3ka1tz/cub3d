/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:48:54 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/16 09:55:25 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	get_map_width(t_map *map)
{
	int	longest_line;
	int	actual_line;
	int	i;

	i = 0;
	longest_line = 0;
	while (map->file[i])
	{
		if (!is_attribute(map->file[i]) && ft_strcmp(map->file[i], "\n"))
			break ;
		i ++;
	}
	while (map->file[i])
	{
		actual_line = ft_strlen(map->file[i]);
		if (longest_line < actual_line)
			longest_line = actual_line;
		i ++;
	}
	map->cols = longest_line;
}

static int	get_map_height(t_map *map)
{
	int	i;
	int	init;
	int	rows;

	i = 0;
	init = 0;
	rows = 0;
	while (map->file[i])
	{
		if (!is_attribute(map->file[i]) && ft_strcmp(map->file[i], "\0"))
		{
			if (init == 0)
				init = i;
			rows ++;
		}
		i ++;
	}
	if (i == 0 || rows == 0)
	{
		printf("Error: Invalid content\n");
		free_array(map->file);
		exit(1);
	}
	map->rows = rows;
	return (init);
}

static char	*copy_line(const char *line, int cols)
{
	char	*new_line;
	int		i;

	new_line = malloc(cols + 1);
	if (!new_line)
	{
		perror("malloc failed");
		exit(1);
	}
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i ++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	**extract_grid(t_map *map)
{
	size_t	src_x;
	size_t	dst_x;
	char	**grid;

	src_x = get_map_height(map);
	dst_x = 0;
	get_map_width(map);
	grid = malloc(sizeof(char *) * (map->rows + 1));
	if (!grid)
	{
		perror("malloc failed");
		exit(1);
	}
	while (map->file[src_x])
	{
		if (!ft_strcmp(map->file[src_x], "\0"))
			break ;
		grid[dst_x] = copy_line(map->file[src_x], map->cols);
		dst_x++;
		src_x++;
	}
	grid[dst_x] = NULL;
	return (grid);
}
