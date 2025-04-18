/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:17:02 by aule-bre          #+#    #+#             */
/*   Updated: 2025/04/15 11:00:52 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf(WRONG_NUMBER_ARG), 1);
	ft_memset(&data, 0, sizeof(t_data));
	if (parse(av[1], &data) == false)
		return (1);
	if (init_window(&data) == false)
		close_mlx_error(&data);
	print_back(&data);
	print_ray(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_hook(data.win, 17, 0, close_mlx, &data);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
