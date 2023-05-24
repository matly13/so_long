/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:15:24 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/24 12:55:57 by mbasile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_sprite(t_vars *vars)
{
	int	x;

	x = 64;
	vars->sprite.background = mlx_xpm_file_to_image(vars->mlx,
			"sprite/background.xpm", &x, &x);
	vars->sprite.wall = mlx_xpm_file_to_image(vars->mlx,
			"sprite/wall.xpm", &x, &x);
	vars->sprite.coin = mlx_xpm_file_to_image(vars->mlx,
			"sprite/coin.xpm", &x, &x);
	vars->sprite.player = mlx_xpm_file_to_image(vars->mlx,
			"sprite/player.xpm", &x, &x);
	vars->sprite.escape = mlx_xpm_file_to_image(vars->mlx,
			"sprite/escape.xpm", &x, &x);
}

void	init_struct(t_vars *vars)
{
	vars->p_pos.x = 0;
	vars->p_pos.y = 0;
}

void	load_map(t_vars *vars)
{
	int	i;
	int	j;

	init_struct(vars);
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '0' || vars->map[i][j] == '1')
				check_01(i, j, vars);
			else if (vars->map[i][j] == 'P' || vars->map[i][j] == 'E'
					|| vars->map[i][j] == 'C')
				check_pec(i, j, vars);
			j++;
		}
		i++;
	}
}
