/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:22:41 by iullibar          #+#    #+#             */
/*   Updated: 2025/10/13 12:37:30 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_dda(t_player *player)
{
	if (player->ray_dir_x < 0)
	{
		player->step_x = -1;
		player->side_x = (player->pos_x - player->map_x) * player->delta_x;
	}
	else
	{
		player->step_x = 1;
		player->side_x = (player->map_x + 1 - player->pos_x) * player->delta_x;
	}
	if (player->ray_dir_y < 0)
	{
		player->step_y = -1;
		player->side_y = (player->pos_y - player->map_y) * player->delta_y;
	}
	else
	{
		player->step_y = 1;
		player->side_y = (player->map_y + 1 - player->pos_y) * player->delta_y;
	}
}

int	perform_dda(t_map *mapa, t_player *player)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (player->side_x < player->side_y)
		{
			player->side_x += player->delta_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_y += player->delta_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (mapa->map[player->map_y][player->map_x] == '1')
			hit = 1;
	}
	return (player->side);
}

void	calculate_wall_data(t_player *player)
{
	double	dist;

	if (player->side == 0)
		dist = (player->map_x - player->pos_x + (1.0 - player->step_x) / 2.0)
			/ player->ray_dir_x;
	else
		dist = (player->map_y - player->pos_y + (1.0 - player->step_y) / 2.0)
			/ player->ray_dir_y;
	player->height = (int)(HEIGHT / dist);
	if (player->side == 0)
		player->wall_x = player->pos_y + dist * player->ray_dir_y;
	else
		player->wall_x = player->pos_x + dist * player->ray_dir_x;
	player->wall_x -= floor(player->wall_x);
	player->start = (HEIGHT - player->height) / 2;
	player->end = player->start + player->height;
	if (player->start < 0)
		player->start = 0;
	if (player->end > HEIGHT)
		player->end = HEIGHT;
}

t_texture	*select_texture(t_game *game, t_player *player)
{
	if (player->side == 0)
	{
		if (player->ray_dir_x > 0)
			return (&game->ea_texture);
		else
			return (&game->we_texture);
	}
	else
	{
		if (player->ray_dir_y > 0)
			return (&game->so_texture);
		else
			return (&game->no_texture);
	}
}

void	raycasting(t_game *game, t_player *player)
{
	int			i;
	t_texture	*xpm;

	i = 0;
	while (i < WIDTH)
	{
		player->camera_x = 2 * i / (double)WIDTH - 1;
		player->ray_dir_x = player->dir_x + player->plane_x * player->camera_x;
		player->ray_dir_y = player->dir_y + player->plane_y * player->camera_x;
		player->map_x = (int)(player->pos_x);
		player->map_y = (int)(player->pos_y);
		player->delta_x = fabs(1 / player->ray_dir_x);
		player->delta_y = fabs(1 / player->ray_dir_y);
		init_dda(player);
		perform_dda(&game->map, player);
		calculate_wall_data(player);
		xpm = select_texture(game, player);
		draw_3d(game, player, xpm, i);
		i ++;
	}
}
