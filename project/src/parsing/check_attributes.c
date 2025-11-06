/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_attributes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:17:07 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/17 09:48:57 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	assign_attributes(t_map *map, char **attr)
{
	if (ft_strcmp(attr[0], "NO") == 0 && !map->no_xpm)
		map->no_xpm = ft_strdup(attr[1]);
	else if (ft_strcmp(attr[0], "SO") == 0 && !map->so_xpm)
		map->so_xpm = ft_strdup(attr[1]);
	else if (ft_strcmp(attr[0], "EA") == 0 && !map->ea_xpm)
		map->ea_xpm = ft_strdup(attr[1]);
	else if (ft_strcmp(attr[0], "WE") == 0 && !map->we_xpm)
		map->we_xpm = ft_strdup(attr[1]);
	else if (ft_strcmp(attr[0], "F") == 0 && !map->f_color)
		map->f_color = ft_strdup(attr[1]);
	else if (ft_strcmp(attr[0], "C") == 0 && !map->c_color)
		map->c_color = ft_strdup(attr[1]);
	else
	{
		printf("Error: Duplicate '%s' attribute was found in map.\n", attr[0]);
		free_array(attr);
		free_map(map, 1);
	}
}

void	check_attributes(t_map *map, char **attr)
{
	if (ft_strcmp(attr[0], "NO") && ft_strcmp(attr[0], "SO")
		&& ft_strcmp(attr[0], "WE") && ft_strcmp(attr[0], "EA")
		&& ft_strcmp(attr[0], "F") && ft_strcmp(attr[0], "C"))
	{
		if (attributes_asigned(map))
			return ;
		printf("Error: Invalid attribute was found in map.\n");
		free_array(attr);
		free_map(map, 1);
	}
	if (!attr[1])
	{
		printf("Error: No value was assigned to '%s' attribute.\n", attr[0]);
		free_array(attr);
		free_map(map, 1);
	}
	if (!ft_strcmp("\n", attr[1]))
	{
		printf("Error: No value was assigned to '%s' attribute.\n", attr[0]);
		free_array(attr);
		free_map(map, 1);
	}
	assign_attributes(map, attr);
}
