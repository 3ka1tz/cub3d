/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:52:57 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/14 13:03:08 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	print_game_manual(void)
{
	printf(
		"-------------------------------------\n"
		"█        █▀▀     █   ▀▀█ █▀▄        █\n"
		"█        █   █ █ █▀█  ▀▄ █ █        █\n"
		"█        ▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀▀         █\n"
		"█       elopez-u and iullibar       █\n"
		"█                                   █\n"
		"█          W: move forward          █\n"
		"█          A: move left             █\n"
		"█          S: move backward         █\n"
		"█          D: move right            █\n"
		"█          <: look left             █\n"
		"█          >: look right            █\n"
		"-------------------------------------\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || argv[1][0] == '\0')
	{
		printf("Error: Map file needed\n");
		return (1);
	}
	game.map.filename = argv[1];
	validate_file(&game.map);
	init_game(&game, &game.player);
	print_game_manual();
	mlx_loop_hook (game.mlx, cubed_render, &game);
	mlx_hook (game.win, 17, 1L << 17, closewindow, &game);
	mlx_hook (game.win, 2, KeyPressMask, handle_keypress, &game);
	mlx_hook (game.win, 3, KeyReleaseMask, handle_keyrelease, &game);
	mlx_loop (game.mlx);
	return (0);
}
