/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attributes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:49:39 by iullibar          #+#    #+#             */
/*   Updated: 2025/10/17 09:49:10 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_fc(t_map *map, char *color)
{
	char	**num;
	int		i;
	int		z;

	i = 0;
	num = ft_split(color, ',');
	while (num[i])
	{
		z = 0;
		while (num[i][z])
		{
			if (!(num[i][z] >= '0' && num[i][z] <= '9'))
				return (printf("Error: Non digit caracter\n"), \
											free_array(num), free_map(map, 1));
			z ++;
		}
		if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
			return (printf("Error: Invalid number for RGB standard\n"), \
											free_array(num), free_map(map, 1));
		i ++;
	}
	if (i < 3 || i > 3)
		return (printf("Error: Invalid number for RGB standard\n"), \
											free_array(num), free_map(map, 1));
	free_array(num);
}

static void	asign_colors(t_map *map)
{
	int		r;
	int		g;
	int		b;
	char	*line;

	line = map->f_color;
	while (*line && (*line == 'F' || *line == ' '))
		line ++;
	r = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	g = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	b = ft_atoi(line);
	map->floor_color = (r << 16) | (g << 8) | b;
	line = map->c_color;
	while (*line && (*line == 'C' || *line == ' '))
		line ++;
	r = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	g = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	b = ft_atoi(line);
	map->ceiling_color = (r << 16) | (g << 8) | b;
}

void	parse_attributes(t_map *map)
{
	int		i;
	char	**attr;

	i = 0;
	while (map->file[i])
	{
		if (i == 0 && map->file[i] == NULL)
			return (printf("Error: Empty map\n"), exit(1));
		if (map->file[i] == NULL)
			break ;
		if (ft_strcmp(map->file[i], "\0"))
		{
			attr = ft_split(map->file[i], ' ');
			if (attr[0] != NULL)
				check_attributes(map, attr);
			free_array(attr);
		}
		else if (attributes_asigned(map))
			break ;
		i ++;
	}
	check_fc(map, map->c_color);
	check_fc(map, map->f_color);
	asign_colors(map);
}
