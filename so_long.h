/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:20:21 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/15 17:49:41 by mbasile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"

# define ERR_MAP_1 "Error\nTi sei dimenticato qualcosa, coglione!\n"
# define ERR_MAP_2 "Error\nLa mappa non é rettangolare, testa di cazzo!\n"
# define ERR_MAP_3 "Error\nI muri sono sbagliati, minkione!\n"
# define ERR_MAP_4 "Error\nManca Pippo Franco, rincoglionito!\n"

typedef	struct s_sprite {
	void	*wall;
	void	*player;
	void	*coin;
	void	*escape;
	void	*background;
}	t_sprite;

typedef struct s_maps {
	int		map_h;
	int		map_w;
}	t_maps;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	char		**map;
	t_maps		map_info;
	int			nb_player;
	int			coin;
	int			escape;
	t_sprite	sprite;
}	t_vars;

void    load_map(t_vars *vars);

#endif