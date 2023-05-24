/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:16:56 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/23 14:16:57 by mbasile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_vars *vars)
{
	if (vars->map[vars->p_pos.y][vars->p_pos.x + 1] == '0')
	{
		vars->map[vars->p_pos.y][vars->p_pos.x + 1] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.x++;
	}
	else if (vars->map[vars->p_pos.y][vars->p_pos.x + 1] == 'C')
	{
		vars->collected++;
		vars->map[vars->p_pos.y][vars->p_pos.x + 1] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.x++;
	}
	else if (vars->map[vars->p_pos.y][vars->p_pos.x + 1] == 'E'
			&& vars->collected == vars->coin)
	{
		vars->map[vars->p_pos.y][vars->p_pos.x + 1] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.x++;
		end_game(vars);
	}
}

void	ft_move_left(t_vars *vars)
{
	if (vars->map[vars->p_pos.y][vars->p_pos.x - 1] == '0')
	{
		vars->map[vars->p_pos.y][vars->p_pos.x - 1] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.x--;
	}
	else if (vars->map[vars->p_pos.y][vars->p_pos.x - 1] == 'C')
	{
		vars->collected++;
		vars->map[vars->p_pos.y][vars->p_pos.x - 1] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.x--;
	}
	else if (vars->map[vars->p_pos.y][vars->p_pos.x - 1] == 'E'
			&& vars->collected == vars->coin)
	{
		vars->map[vars->p_pos.y][vars->p_pos.x - 1] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.x--;
		end_game(vars);
	}
}

void	ft_move_up(t_vars *vars)
{
	if (vars->map[vars->p_pos.y - 1][vars->p_pos.x] == '0')
	{
		vars->map[vars->p_pos.y - 1][vars->p_pos.x] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.y--;
	}
	else if (vars->map[vars->p_pos.y - 1][vars->p_pos.x] == 'C')
	{
		vars->collected++;
		vars->map[vars->p_pos.y - 1][vars->p_pos.x] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.y--;
	}
	else if (vars->map[vars->p_pos.y - 1][vars->p_pos.x] == 'E'
			&& vars->collected == vars->coin)
	{
		vars->map[vars->p_pos.y - 1][vars->p_pos.x] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.y--;
		end_game(vars);
	}
}

void	ft_move_down(t_vars *vars)
{
	if (vars->map[vars->p_pos.y + 1][vars->p_pos.x] == '0')
	{
		vars->map[vars->p_pos.y + 1][vars->p_pos.x] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.y++;
	}
	else if (vars->map[vars->p_pos.y + 1][vars->p_pos.x] == 'C')
	{
		vars->collected++;
		vars->map[vars->p_pos.y + 1][vars->p_pos.x] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.y++;
	}
	else if (vars->map[vars->p_pos.y + 1][vars->p_pos.x] == 'E'
			&& vars->collected == vars->coin)
	{
		vars->map[vars->p_pos.y + 1][vars->p_pos.x] = 'P';
		vars->map[vars->p_pos.y][vars->p_pos.x] = '0';
		vars->p_pos.y++;
		end_game(vars);
	}
}

int	ft_key_control(int kc, t_vars *vars)
{
	int	x;
	int	y;

	x = vars->p_pos.x;
	y = vars->p_pos.y;
	if (kc == 100 || kc == 119 || kc == 97 || kc == 115 || kc == 65307)
	{
		if (kc == 65307)
			end_game(vars);
		if (kc == 100)
			ft_move_right(vars);
		if (kc == 97)
			ft_move_left(vars);
		if (kc == 119)
			ft_move_up(vars);
		if (kc == 115)
			ft_move_down(vars);
		load_map(vars);
		if (vars->p_pos.x != x || vars->p_pos.y != y)
		{
			vars->counter++;
			ft_printf("moves: %d\n", vars->counter);
		}
	}
	return (0);
}
