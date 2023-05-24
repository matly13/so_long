/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:16:37 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/23 14:16:38 by mbasile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_map(char *str, t_vars *vars)
{
	int	i;

	i = -1;
	ft_printf(str);
	while (vars->map[++i])
		free(vars->map[i]);
	free(vars->map);
	free(vars);
	exit(1);
}

void	check_map(t_vars *vars)
{
	check_char(vars);
	check_rect(vars);
	check_wall(vars);
	check_min_req(vars);
}

void	get_height(char *s, t_vars *vars)
{
	int		fd;
	char	*line;

	vars->map_info.map_h = 0;
	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		vars->map_info.map_h++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	get_map(char *s, t_vars	*vars)
{
	char	*line;
	int		fd;
	int		i;

	check_name(s, vars);
	get_height(s, vars);
	i = 0;
	vars->map = malloc(sizeof(char *) * (vars->map_info.map_h + 1));
	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		vars->map[i] = ft_strdup(line);
		if (vars->map[i][ft_strlen(vars->map[i]) - 1] == '\n')
			vars->map[i][ft_strlen(vars->map[i]) - 1] = 0;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	vars->map[i] = NULL;
	free(line);
	close(fd);
	check_map(vars);
}
