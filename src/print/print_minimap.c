/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:11:03 by aule-bre          #+#    #+#             */
/*   Updated: 2025/03/26 17:57:49 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	fill_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (++i < 32)
	{
		j = 0;
		while (++j < 32)
			mlx_pixel_put(data->mlx, data->win, 32 * x + i, 32 * y + j, color);
	}
}

void	fill_all(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '0')
				fill_square(data, j, i, 12247551);
			else if (data->map[i][j] == '1')
				fill_square(data, j, i, 16757690);
			else if (ft_strrchr("NSEW", data->map[i][j]))
				fill_square(data, j, i, 12255177);
		}
	}
}

void	print_player(t_data *data)
{
	int	i;
	int	j;

	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
			mlx_pixel_put(data->mlx, data->win, data->player.x / 2 + i,
					data->player.y / 2 + j, 16711680);
	}
}

void	print_minimap(t_data *data)
{
	int	i;
	int	len;

	i = -1;
	mlx_clear_window(data->mlx, data->win);
	while (++i < data->map_size.x + 1)
	{
		len = -1;
		while (++len < 32 * data->map_size.y)
			mlx_pixel_put(data->mlx, data->win, len, i * 32, 5919317);
	}
	i = -1;
	while (++i < data->map_size.y + 1)
	{
		len = -1;
		while (++len < 32 * data->map_size.x)
			mlx_pixel_put(data->mlx, data->win, i * 32, len, 5919317);
	}
	//fill_all(data);
	print_player(data);
	//print_ray(data);
}
