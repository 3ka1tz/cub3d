/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:40:27 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/16 10:19:07 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_map(t_map *map)
{
	map->no_xpm = NULL;
	map->so_xpm = NULL;
	map->ea_xpm = NULL;
	map->we_xpm = NULL;
	map->f_color = NULL;
	map->c_color = NULL;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->file = NULL;
	map->rows = 0;
	map->cols = 0;
	map->dir = '\0';
	map->x = 0;
	map->y = 0;
	map->map = NULL;
}

static void	validate_extension(const char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strcmp(extension, ".cub") != 0)
	{
		printf("Error: Map file extension must be .cub\n");
		exit(1);
	}
}

void	validate_file(t_map *map)
{
	int		fd;

	validate_extension(map->filename);
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return (printf("Error: File not found\n"), exit(1));
	close(fd);
	init_map(map);
	map->file = extract_content(map->filename);
	parse_attributes(map);
	map->map = extract_grid(map);
	validate_map(map);
}
