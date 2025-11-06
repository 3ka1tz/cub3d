/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:03:23 by iullibar          #+#    #+#             */
/*   Updated: 2025/10/17 09:00:10 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
}

void	init_game(t_game *game, t_player *player)
{
	init_keys(&game->keys);
	player->pos_x = game->map.x + 0.5;
	player->pos_y = game->map.y + 0.5;
	know_starting_angle(&game->map, player);
	set_player_dir(player);
	game->mlx = mlx_init();
	load_textures(game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	game->img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->pixel_ptr = mlx_get_data_addr(game->img_ptr, &game->bpp,
			&game->len, &game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img_ptr, 0, 0);
}

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, game);
			x ++;
		}
		y ++;
	}
}

int	cubed_render(t_game *game)
{
	clear_image(game);
	update_player(game);
	raycasting(game, &game->player);
	mlx_put_image_to_window(game->mlx, game->win, game->img_ptr, 0, 0);
	return (0);
}
