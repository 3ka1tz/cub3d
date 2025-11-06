/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:05:48 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/16 12:18:56 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_player(t_player *player, char **map_array, double dy, double dx)
{
	double	r;
	double	new_y;
	double	new_x;

	r = 0.25;
	new_y = player->pos_y + dy;
	new_x = player->pos_x + dx;
	if (map_array[(int)player->pos_y][(int)(new_x + r)] != '1' && \
		map_array[(int)player->pos_y][(int)(new_x - r)] != '1')
		player->pos_x = new_x;
	if (map_array[(int)(new_y + r)][(int)player->pos_x] != '1' && \
		map_array[(int)(new_y - r)][(int)player->pos_x] != '1')
		player->pos_y = new_y;
}
