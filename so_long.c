#include "so_long.h"

void	check_name(char *s, t_vars *vars)
{
	int	len;

	len = ft_strlen(s);
	if (s[len - 1] != 'r' || s[len - 2] != 'e' || s[len - 3] != 'b' || s[len - 4] != '.')
	{
		ft_printf("Error\n");
		free(vars);
		exit(0);
	}
}

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

void	check_map(t_vars *vars)
{
	check_char(vars);
	check_rect(vars);
	check_wall(vars);
	check_min_req(vars);
}

void	get_map(char *s, t_vars	*vars)
{
	char	*line;
	int		fd;
	int		i;

	check_name(s, vars);
	i = 0;
	vars->map_info.map_h = 0;
	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		vars->map_info.map_h++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	vars->map = malloc(sizeof(char *) * (vars->map_info.map_h + 1));
	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	while(line)
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

int	main(int ac, char **av)
{
	t_vars	*vars;
	int		i = 0;

	if (ac != 2)
	{
		printf("Error\n");
		return (0);
	}
	vars = malloc(sizeof(t_vars));
	get_map(av[1], vars);
	// vars->mlx = 
	while (vars->map[i])
	{
		ft_printf("%s\n",vars->map[i]);
		i++;
	}
	return (0);
}