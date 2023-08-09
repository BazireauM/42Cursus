/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:07:29 by mbazirea          #+#    #+#             */
/*   Updated: 2023/07/26 23:52:49 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init(t_map *map, t_all *all)
{
	mlx_t	*win;
	t_img	*img;

	win = mlx_init(20 * map->lenx, 20 * map->leny, "so_long", 1);
	img = init_img(win);
	first_print(win, img, map);
	all->img = img;
	all->map = map;
	all->win = win;
	all->n_move = 0;
	init_pos_fox(all);
	init_n_item(all);
}

void	init_n_item(t_all *all)
{
	int	x;
	int	y;

	all->n_item = 0;
	x = 0;
	while (x < all->map->lenx)
	{
		y = 0;
		while (y < all->map->leny)
		{
			if (all->map->map[y][x] == 'C')
				all->n_item += 1;
			y++;
		}
		x++;
	}
}

void	init_pos_fox(t_all *all)
{
	int	x;
	int	y;

	all->n_item_disable = 0;
	x = 0;
	while (x < all->map->lenx)
	{
		y = 0;
		while (y < all->map->leny)
		{
			if (all->map->map[y][x] == 'P')
			{
				all->x_fox = x;
				all->y_fox = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
