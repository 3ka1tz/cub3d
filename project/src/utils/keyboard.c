/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:23:15 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/10 14:11:17 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	closewindow(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_ptr);
	mlx_destroy_image(game->mlx, game->no_texture.img);
	mlx_destroy_image(game->mlx, game->so_texture.img);
	mlx_destroy_image(game->mlx, game->ea_texture.img);
	mlx_destroy_image(game->mlx, game->we_texture.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(&game->map, 0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		closewindow(game);
	if (keycode == XK_w)
		game->keys.w = 1;
	if (keycode == XK_s)
		game->keys.s = 1;
	if (keycode == XK_a)
		game->keys.a = 1;
	if (keycode == XK_d)
		game->keys.d = 1;
	if (keycode == XK_Left)
		game->keys.left = 1;
	if (keycode == XK_Right)
		game->keys.right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys.w = 0;
	if (keycode == XK_s)
		game->keys.s = 0;
	if (keycode == XK_a)
		game->keys.a = 0;
	if (keycode == XK_d)
		game->keys.d = 0;
	if (keycode == XK_Left)
		game->keys.left = 0;
	if (keycode == XK_Right)
		game->keys.right = 0;
	return (0);
}
