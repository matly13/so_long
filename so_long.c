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

void	get_map(char *s, t_vars	*vars)
{
	check_name(s, vars);
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
	// printf("%s\n", av[1]);
	get_map(av[1], vars);
	return (0);
}