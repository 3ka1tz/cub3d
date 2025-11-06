/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:31:11 by iullibar          #+#    #+#             */
/*   Updated: 2025/10/16 13:35:38 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->len + x * game->bpp / 8;
	game->pixel_ptr[index] = color & 0xFF;
	game->pixel_ptr[index + 1] = (color >> 8) & 0xFF;
	game->pixel_ptr[index + 2] = (color >> 16) & 0xFF;
}

int	calc_color(t_player *player, t_texture *xpm, int tex_x)
{
	int		offset;
	int		color;
	int		tex_y;
	int		d;

	d = player->start * 256 - HEIGHT * 128 + player->height * 128;
	tex_y = (d * xpm->height) / player->height / 256;
	if (tex_x < 0 || tex_x >= xpm->width || tex_y < 0 || tex_y >= xpm->height)
		return (-1);
	offset = tex_y * xpm->len + tex_x * (xpm->bpp / 8);
	if (offset < 0 || offset + 3 >= xpm->height * xpm->len)
		return (-1);
	color = *(int *)(xpm->addr + offset);
	return (color);
}

void	draw_wall(t_game *game, t_player *player, t_texture *xpm, int i)
{
	double	wall_x;
	int		tex_x;
	int		color;

	wall_x = player->wall_x - floor(player->wall_x);
	tex_x = (int)(wall_x * xpm->width);
	if ((player->side == 0 && player->ray_dir_x < 0)
		|| (player->side == 1 && player->ray_dir_y > 0))
		tex_x = xpm->width - tex_x - 1;
	while (player->start < player->end)
	{
		color = calc_color(player, xpm, tex_x);
		if (color != -1)
			put_pixel(i, player->start, color, game);
		player->start ++;
	}
}

void	draw_3d(t_game *game, t_player *player, t_texture *xpm, int i)
{
	int	y;

	y = HEIGHT;
	while (y > HEIGHT / 2)
	{
		put_pixel(i, y, game->map.floor_color, game);
		y --;
	}
	y = HEIGHT / 2;
	while (y > 0)
	{
		put_pixel(i, y, game->map.ceiling_color, game);
		y --;
	}
	draw_wall (game, player, xpm, i);
}
