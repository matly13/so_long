/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:17:06 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/23 16:54:29 by mbasile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->map_info.map_h)
		free(vars->map[i]);
	free(vars->map);
	mlx_destroy_image(vars->mlx, vars->sprite.background);
	mlx_destroy_image(vars->mlx, vars->sprite.player);
	mlx_destroy_image(vars->mlx, vars->sprite.wall);
	mlx_destroy_image(vars->mlx, vars->sprite.coin);
	mlx_destroy_image(vars->mlx, vars->sprite.escape);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	exit(0);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2)
	{
		printf("Error\n");
		return (0);
	}
	vars = malloc(sizeof(t_vars));
	get_map(av[1], vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_info.map_w * 64,
			vars->map_info.map_h * 64, "so_long");
	vars->collected = 0;
	vars->counter = 0;
	upload_sprite(vars);
	load_map(vars);
	mlx_hook(vars->win, 17, 0, end_game, vars);
	mlx_hook(vars->win, 2, 1L << 0, ft_key_control, vars);
	mlx_loop(vars->mlx);
	return (0);
}
