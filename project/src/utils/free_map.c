/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:37:30 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/06 13:30:04 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(t_map *map, int status)
{
	free(map->no_xpm);
	free(map->so_xpm);
	free(map->ea_xpm);
	free(map->we_xpm);
	free(map->f_color);
	free(map->c_color);
	free_array(map->map);
	free_array(map->file);
	exit(status);
}
