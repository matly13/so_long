/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:59:47 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/24 12:56:22 by mbasile          ###   ########.fr       */
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

typedef struct s_sprite {
	void	*wall;
	void	*player;
	void	*coin;
	void	*escape;
	void	*background;
}	t_sprite;

typedef struct s_vector {
	int	x;
	int	y;
}	t_vector;

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
	int			collected;
	t_sprite	sprite;
	t_vector	p_pos;
	int			counter;
}	t_vars;

/* MAP FUNCTION */

void	ft_error_map(char *str, t_vars *vars);
void	check_map(t_vars *vars);
void	get_height(char *s, t_vars *vars);
void	get_map(char *s, t_vars	*vars);
void	check_name(char *s, t_vars *vars);
void	check_rect(t_vars *vars);
void	check_min_req(t_vars *vars);
void	check_wall(t_vars *vars);
void	check_char(t_vars *vars);

void	load_map(t_vars *vars);
int		ft_key_control(int kc, t_vars *vars);
int		end_game(t_vars *vars);
void	upload_sprite(t_vars *vars);
void	check_01(int i, int j, t_vars *vars);
void	check_pec(int i, int j, t_vars *vars);

#endif