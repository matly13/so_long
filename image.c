/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:32:52 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/15 17:54:09 by mbasile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    upload_sprite(t_vars *vars)
{
	int	x;

	x = 64;
    vars->sprite.background = mlx_xpm_file_to_image(vars->mlx, "sprite/background.xpm", &x, &x);
    vars->sprite.wall = mlx_xpm_file_to_image(vars->mlx, "sprite/wall.xpm", &x, &x);
    vars->sprite.coin = mlx_xpm_file_to_image(vars->mlx, "sprite/coin.xpm", &x, &x);
    vars->sprite.player = mlx_xpm_file_to_image(vars->mlx, "sprite/player.xpm", &x, &x);
    vars->sprite.escape = mlx_xpm_file_to_image(vars->mlx, "sprite/escape.xpm", &x, &x);
}

void    load_map(t_vars *vars)
{
    int i;
    int j;

	upload_sprite(vars);
    i = 0;
    while (vars->map[i])
    {
        j = 0;
        while (vars->map[i][j])
        {
            if (vars->map[i][j] == '0')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.background, j, i);
            else if (vars->map[i][j] == '1')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.wall, j, i);
            else if (vars->map[i][j] == 'P')
            {
                mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.background, j, i);
                mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.player, j, i);
            }
			else if (vars->map[i][j] == 'E')
            {
                mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.background, j, i);
                mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.escape, j, i);
            }
			else if (vars->map[i][j] == 'C')
            {
                mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.background, j, i);
                mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite.coin, j, i);
            }
			j++;
        }
		i++;
    }
}
