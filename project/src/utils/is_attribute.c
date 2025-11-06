/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_attribute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:49:50 by iullibar          #+#    #+#             */
/*   Updated: 2025/10/15 14:56:39 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	attributes_asigned(t_map *map)
{
	if (map->no_xpm
		&& map->so_xpm
		&& map->ea_xpm
		&& map->we_xpm
		&& map->f_color
		&& map->c_color)
		return (1);
	return (0);
}

int	is_attribute(char *line)
{
	if (ft_strncmp(line, "NO ", 3) && ft_strncmp(line, "SO ", 3)
		&& ft_strncmp(line, "WE ", 3) && ft_strncmp(line, "EA ", 3)
		&& ft_strncmp(line, "F ", 2) && ft_strncmp(line, "C ", 2)
		&& ft_strcmp(line, "NO") && ft_strcmp(line, "SO")
		&& ft_strcmp(line, "WE") && ft_strcmp(line, "EA")
		&& ft_strcmp(line, "F") && ft_strcmp(line, "C")
	)
		return (0);
	return (1);
}
