/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:07:58 by iullibar          #+#    #+#             */
/*   Updated: 2025/10/16 09:58:02 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_textures(t_game *game)
{
	game->no_texture.img = NULL;
	game->so_texture.img = NULL;
	game->ea_texture.img = NULL;
	game->we_texture.img = NULL;
}

void	load_texture(t_game *game, t_texture *xpm, char *filename)
{
	xpm->img = mlx_xpm_file_to_image(game->mlx, filename,
			&xpm->width, &xpm->height);
	if (!xpm->img)
	{
		printf("Error: Failed to load texture\n");
		if (game->no_texture.img)
			mlx_destroy_image(game->mlx, game->no_texture.img);
		if (game->so_texture.img)
			mlx_destroy_image(game->mlx, game->so_texture.img);
		if (game->ea_texture.img)
			mlx_destroy_image(game->mlx, game->ea_texture.img);
		if (game->we_texture.img)
			mlx_destroy_image(game->mlx, game->we_texture.img);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(&game->map, 1);
	}
	xpm->addr = mlx_get_data_addr(xpm->img, &xpm->bpp,
			&xpm->len, &xpm->endian);
}

void	load_textures(t_game *game)
{
	init_textures(game);
	load_texture(game, &game->no_texture, game->map.no_xpm);
	load_texture(game, &game->so_texture, game->map.so_xpm);
	load_texture(game, &game->ea_texture, game->map.ea_xpm);
	load_texture(game, &game->we_texture, game->map.we_xpm);
}
