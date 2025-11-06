/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:02:14 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/15 12:00:20 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	calc_movement(t_game *game, t_player *player,
												double new_x, double new_y)
{
	double	speed;

	speed = 0.15;
	if (game->keys.w)
	{
		new_x += player->dir_x * speed;
		new_y += player->dir_y * speed;
	}
	if (game->keys.s)
	{
		new_x -= player->dir_x * speed;
		new_y -= player->dir_y * speed;
	}
	if (game->keys.a)
	{
		new_x -= player->plane_x * speed;
		new_y -= player->plane_y * speed;
	}
	if (game->keys.d)
	{
		new_x += player->plane_x * speed;
		new_y += player->plane_y * speed;
	}
	move_player(player, game->map.map, new_y, new_x);
}

static void	rotate_player(t_keys *keys, t_player *player)
{
	if (keys->left)
		player->start_ang += 0.05;
	if (keys->right)
		player->start_ang -= 0.05;
	set_player_dir(player);
}

void	update_player(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = 0.0;
	new_y = 0.0;
	calc_movement(game, &game->player, new_x, new_y);
	rotate_player(&game->keys, &game->player);
}
