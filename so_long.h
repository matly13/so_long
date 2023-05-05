#ifndef SO_LONG_H
# define SO_LONG_H

// # include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_vars {
	void			*mlx;
	void			*win;
	int				win_w;
	int				win_h;
	char			**map;
}	t_vars;

#endif