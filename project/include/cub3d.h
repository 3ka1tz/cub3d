/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:52:19 by elopez-u          #+#    #+#             */
/*   Updated: 2025/10/17 09:57:51 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define PI 3.1415

# define WIDTH	1920
# define HEIGHT	1080

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		len;
	int		endian;
}	t_texture;

typedef struct s_player
{
	int			height;
	int			start;
	int			end;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			xpm_x;
	int			xpm_y;
	int			side;
	double		side_x;
	double		side_y;
	double		pos_x;
	double		pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_x;
	double		delta_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		wall_x;
	double		camera_x;
	double		start_ang;
}	t_player;

typedef struct s_map
{
	char		*filename;
	char		**file;

	char		*no_xpm;
	char		*so_xpm;
	char		*ea_xpm;
	char		*we_xpm;

	char		*f_color;
	char		*c_color;
	int			floor_color;
	int			ceiling_color;

	char		**map;
	int			rows;
	int			cols;
	char		dir;
	int			x;
	int			y;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	char		*pixel_ptr;
	int			bpp;
	int			len;
	int			endian;
	t_map		map;
	t_keys		keys;
	t_player	player;
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	ea_texture;
	t_texture	we_texture;
}	t_game;

/* parsing */
void			validate_file(t_map *map);
char			**extract_content(char *file);
void			parse_attributes(t_map *map);
void			check_attributes(t_map *map, char **attr);
void			assign_attributes(t_map *map, char **attr);
char			**extract_grid(t_map *map);
void			validate_map(t_map *map);

/* render */
void			init_game(t_game *game, t_player *player);
void			know_starting_angle(t_map *map, t_player *player);
void			set_player_dir(t_player *player);
void			load_textures(t_game *game);
int				cubed_render(t_game *game);
void			raycasting(t_game *game, t_player *player);
void			draw_3d(t_game *game, t_player *player, t_texture *xpm, int i);
void			update_player(t_game *game);
void			move_player(t_player *player, char **map_array, double dy,
					double dx);

/* utils */
void			free_map(t_map *map, int status);
void			free_array(char **arr);
int				is_attribute(char *line);
int				attributes_asigned(t_map *map);
int				handle_keypress(int keycode, t_game *game);
int				handle_keyrelease(int keycode, t_game *game);
int				closewindow(t_game *game);
void			put_pixel(int x, int y, int color, t_game *game);
int				check_line(char *line);

#endif