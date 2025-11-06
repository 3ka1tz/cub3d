/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:25:36 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/17 08:58:34 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	valid_caracter(t_map *map, int y, int x)
{
	char	c;

	c = map->map[y][x];
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && !map->dir)
	{
		map->dir = c;
		map->y = y;
		map->x = x;
		return (0);
	}
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (printf("Error: Duplicate spawn location\n"), 1);
	else if (c == '0' || c == '1' || c == ' ' || c == '	' || c == '\n')
		return (0);
	else
		return (printf("Error: Invalid caracter on the map\n"), 1);
}

static void	flood_fill(t_map *mapa, char **map, int x, int y)
{
	if (y < 0 || y == mapa->rows || !map[y])
		return (printf("Error: Map is not closed\n"), \
										free_array(map), free_map(mapa, 1));
	if (x < 0 || x == mapa->cols)
		return (printf("Error: Map is not closed\n"), \
										free_array(map), free_map(mapa, 1));
	if (map[y][x] == ' ' || map[y][x] == '\n' || map[y][x] == '	'
		|| map[y][x] == '\0')
		return (printf("Error: Map is not closed\n"), \
										free_array(map), free_map(mapa, 1));
	if (map[y][x] && map[y][x] != '1')
	{
		map[y][x] = '1';
		flood_fill(mapa, map, x + 1, y);
		flood_fill(mapa, map, x - 1, y);
		flood_fill(mapa, map, x, y + 1);
		flood_fill(mapa, map, x, y - 1);
	}
}

char	**dupmap(t_map *map)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = malloc((map->rows + 1) * sizeof(char *));
	while (map->map[i])
	{
		new_map[i] = ft_strdup(map->map[i]);
		i ++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	validate_map(t_map *map)
{
	int		x;
	int		y;
	char	**mapa;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (valid_caracter(map, y, x))
				free_map(map, 1);
			x ++;
		}
		y ++;
	}
	if (!map->dir)
		return (printf("Error: One player required\n"), free_map(map, 1));
	mapa = dupmap(map);
	flood_fill(map, mapa, map->x, map->y);
	free_array(mapa);
}
