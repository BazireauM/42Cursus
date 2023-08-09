/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:42:20 by mbazirea          #+#    #+#             */
/*   Updated: 2023/07/26 20:58:11 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../minilibx/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_map
{
	int		lenx;
	int		leny;
	char	**map;
}	t_map;

typedef struct s_img
{
	mlx_texture_t	*doort;
	mlx_texture_t	*foxt;
	mlx_texture_t	*wallt;
	mlx_texture_t	*itemt;
	mlx_texture_t	*nonet;
	mlx_image_t		*door;
	mlx_image_t		*fox;
	mlx_image_t		*wall;
	mlx_image_t		*item;
	mlx_image_t		*none;
}	t_img;

typedef struct s_all
{
	t_img	*img;
	t_map	*map;
	mlx_t	*win;
	int		x_fox;
	int		y_fox;
	int		n_item_disable;
	int		n_item;
	int		n_move;
}	t_all;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

//init.c

void	init(t_map *map, t_all *all);
void	init_pos_fox(t_all *all);
void	init_n_item(t_all *all);

//	test.c

int		test_just_epc01(t_map *map);
int		test_name_file(char *s);
int		test_map(struct s_map *map);
int		rectangle(struct s_map *map);
int		surrounded(struct s_map *map);

//	test2.c

int		test_char(struct s_map *map);
int		test_char_p(struct s_map *map);
int		test_char_e(struct s_map *map);
int		test_char_c(struct s_map *map);
int		count_e_and_c(char **map_cp);

//	test3.c	(full)

int		test_way(struct s_map *map);
int		search_way(char **map_cp);
int		test_new_case(char **map_cp, int i, int b);
char	**cpy_map(struct s_map *map);
char	**init_shearch_way(char **map_cp);

//	parssing.c (full)

char	**parssing(char *map);
char	**append_final(char **final, char *tmp);
char	**append_final2(char **final, char *tmp, char **tmp2, int i);
int		free_all_final(char **final);
int		len_char_char(char **final);

//	free.c

void	free_map(char **map);
void	free_struct_map(t_map *map);
void	final_free(t_all *all);

//	init_img.c

t_img	*init_img(mlx_t *win);
void	first_print(mlx_t *win, t_img *img, t_map *map);
void	chose_and_print(char c, t_img *img, mlx_t *win, t_xy *xy);

//	move.c

void	move(mlx_key_data_t keydata, void *param);
void	move2(mlx_key_data_t keydata, t_all *all);
void	move3(mlx_key_data_t keydata, t_all *all);
void	move4(mlx_key_data_t keydata, t_all *all);
void	choose_and_disable_instance(t_all *all);

#endif
