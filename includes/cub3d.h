/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:19 by aule-bre          #+#    #+#             */
/*   Updated: 2025/04/15 10:29:23 by hadubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// INCLUDES ------------------------------------------------

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// ALIASES ------------------------------------------------

// KEYBINDS

# define FORWARD 0
# define BACKWARD 1
# define LEFT 2
# define RIGHT 3

// ERROR MESSAGES

# define WRONG_MAP_EXT "Error\ninvalid file: wrong map extension\n"
# define WRONG_NUMBER_ARG "Error\nwrong number of arguments\n"
# define ERROR_OPEN "Error\ninvalid file: the file does not exist\n"
# define EMPTY_MAP_FILE "Error\ninvalid file: the map file is empty\n"
# define ERROR_MALLOC "Error\na malloc failed\n"
# define WRONG_IDENTIFIER "Error\ninvalid map: id in the map are not valid\n"
# define INVALID_ELT_ID "Error\ninvalid color: a color is not valid\n"
# define EMPTY_MAP "Error\ninvalid map: the map is empty\n"
# define INVALID_VALUES "Error\ninvalid map: unknown char in the map\n"
# define MULTIPLE_START "Error\ninvalid map: multiple or no start points\n"
# define INVALID_BORDERS "Error\ninvalid map: map isn't correctly closed\n"
# define MLX_FAIL "Error\nmlx: an error occured during mlx initialization\n"
# define MLX_IMG_FAIL "Error\nmlx: conversion to image failed\n"

// SCREEN SHIT

# define SC_HEI 450
# define SC_WID 900

// COLORS

# define PASTEL_PINK 16761052
# define PASTEL_BLUE 11417103
# define PASTEL_GREEN 7852535
# define PASTEL_YELLOW 16645398
# define PASTEL_BROWN 12757889
# define PASTEL_ORANGE 16756103

// STRUCTURES ----------------------------------------------

typedef struct s_coo
{
	int		x;
	int		y;
}			t_coo;

typedef struct s_ray
{
	t_coo	ray;
	t_coo	prev;
	int		i;
}			t_ray;

typedef struct s_sprite
{
	char	*path;
	void	*addr;
}			t_sprite;

typedef struct s_img
{
	char	*path;
	void	*img;
	char	*img_pix;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_data
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	t_img	img;
	int		f[3];
	int		c[3];
	bool	checker_f;
	bool	checker_c;
	int		floor;
	int		ceiling;
	char	**map;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_coo	map_size;
	float	player_angle;
	t_coo	player;
}			t_data;

// PROTOTYPES ----------------------------------------------

// PARSING

bool		parse(char *map_file, t_data *data);
bool		check_map_format(char *map_file);
char		*open_map(char *map_file);
bool		fill_data(char *map_content, t_data *data);
bool		check_map(t_data *data);
bool		check_split_map(char **map);
char		*get_clean_path(char *messy_path);
void		fill_keywords(char **map, t_data *data);
bool		fill_rgb(char *line, int *array);

// MLX INIT

bool		init_window(t_data *data);

// FREE

void		free_tab(void **tab);
void		free_data(t_data *data);
int			close_mlx(t_data *data);
int			close_mlx_error(t_data *data);

// TMP

void		print_minimap(t_data *data);

// KEY HOOKS

int			key_hook(int keycode, t_data *data);

// RAYCAST

void		print_ray(t_data *data);
void		my_pixel_put(int x, int y, t_data *data, int color);
void		print_back(t_data *data);
void		print_line_east(t_data *data, t_ray ray, float r, float fov);
void		print_line_west(t_data *data, t_ray ray, float r, float fov);
void		print_line_north(t_data *data, t_ray ray, float r, float fov);
void		print_line_south(t_data *data, t_ray ray, float r, float fov);

#endif
