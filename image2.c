/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:15:42 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/23 14:16:27 by mbasile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_01(int i, int j, t_vars *vars)
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.wall, j * 64, i * 64);
	else if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.background, j * 64, i * 64);
}

void	check_pec(int i, int j, t_vars *vars)
{
	if (vars->map[i][j] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.player, j * 64, i * 64);
		vars->p_pos.x = j;
		vars->p_pos.y = i;
	}
	else if (vars->map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.escape, j * 64, i * 64);
	else if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->sprite.coin, j * 64, i * 64);
}
