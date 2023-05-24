/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:16:10 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/23 16:55:44 by mbasile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *s, t_vars *vars)
{
	int	len;

	len = ft_strlen(s);
	if (s[len - 1] != 'r' || s[len - 2] != 'e' || s[len - 3] != 'b'
		|| s[len - 4] != '.')
	{
		ft_printf("Error\n");
		free(vars);
		exit(0);
	}
}

void	check_rect(t_vars *vars)
{
	int	i;

	i = 0;
	vars->map_info.map_w = ft_strlen(vars->map[0]);
	while (vars->map[++i])
	{
		if (vars->map_info.map_w != (int)ft_strlen(vars->map[i]))
			ft_error_map(ERR_MAP_2, vars);
	}
}

void	check_min_req(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	vars->nb_player = 0;
	vars->coin = 0;
	vars->escape = 0;
	while (vars->map[++i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				vars->nb_player++;
			else if (vars->map[i][j] == 'C')
				vars->coin++;
			else if (vars->map[i][j] == 'E')
				vars->escape++;
			j++;
		}
	}
	if (vars->nb_player == 0 || vars->coin == 0 || vars->escape == 0)
		ft_error_map(ERR_MAP_4, vars);
}

void	check_wall(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->map_info.map_w)
	{
		if (!(vars->map[0][i] == '1'
			&& vars->map[vars->map_info.map_h - 1][i] == '1'))
			ft_error_map(ERR_MAP_3, vars);
	}
	i = 0;
	while (++i < vars->map_info.map_h - 1)
	{
		if (!(vars->map[i][0] == '1'
			&& vars->map[i][vars->map_info.map_w - 1] == '1'))
			ft_error_map(ERR_MAP_3, vars);
	}
}

void	check_char(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] != '1' && vars->map[i][j] != '0'
				&& vars->map[i][j] != 'P' && vars->map[i][j] != 'E'
				&& vars->map[i][j] != 'C')
				ft_error_map(ERR_MAP_1, vars);
			j++;
		}
	}
}
