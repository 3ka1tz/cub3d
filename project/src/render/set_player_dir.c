/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:30:58 by iullibar          #+#    #+#             */
/*   Updated: 2025/10/10 10:10:57 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	know_starting_angle(t_map *map, t_player *player)
{
	if (map->map[map->y][map->x] == 'N')
		player->start_ang = PI / 2;
	else if (map->map[map->y][map->x] == 'S')
		player->start_ang = 3 * PI / 2;
	else if (map->map[map->y][map->x] == 'E')
		player->start_ang = 2 * PI;
	else if (map->map[map->y][map->x] == 'W')
		player->start_ang = PI;
}

void	set_player_dir(t_player *player)
{
	player->dir_x = cos(player->start_ang);
	player->dir_y = -sin(player->start_ang);
	player->plane_x = -player->dir_y * 0.66;
	player->plane_y = player->dir_x * 0.66;
}
