/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:19:20 by mbazirea          #+#    #+#             */
/*   Updated: 2023/07/26 20:55:09 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_map(t_map *map);

void	move(mlx_key_data_t keydata, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (keydata.key == MLX_KEY_W && keydata.action != MLX_RELEASE)
	{
		if (all->map->map[all->y_fox - 1][all->x_fox] != '1')
		{
			all->img->fox->instances[0].y -= 20;
			all->y_fox -= 1;
			all->n_move += 1;
			ft_printf("%d\n", all->n_move);
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action != MLX_RELEASE)
	{
		if (all->map->map[all->y_fox + 1][all->x_fox] != '1')
		{
			all->img->fox->instances[0].y += 20;
			all->y_fox += 1;
			all->n_move += 1;
			ft_printf("%d\n", all->n_move);
		}
	}
	move2(keydata, all);
	move3(keydata, all);
}

void	move2(mlx_key_data_t keydata, t_all *all)
{
	if (keydata.key == MLX_KEY_D && keydata.action != MLX_RELEASE)
	{
		if (all->map->map[all->y_fox][all->x_fox + 1] != '1')
		{
			all->img->fox->instances[0].x += 20;
			all->x_fox += 1;
			all->n_move += 1;
			ft_printf("%d\n", all->n_move);
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action != MLX_RELEASE)
	{
		if (all->map->map[all->y_fox][all->x_fox - 1] != '1')
		{
			all->img->fox->instances[0].x -= 20;
			all->x_fox -= 1;
			all->n_move += 1;
			ft_printf("%d\n", all->n_move);
		}
	}
}

void	move3(mlx_key_data_t keydata, t_all *all)
{
	if (all->map->map[all->y_fox][all->x_fox] == 'C'
		&& keydata.action != MLX_RELEASE && (keydata.key == MLX_KEY_W
		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_A
		|| keydata.key == MLX_KEY_D))
	{
		choose_and_disable_instance(all);
	}
	if (all->map->map[all->y_fox][all->x_fox] == 'E'
		&& keydata.action != MLX_RELEASE && (keydata.key == MLX_KEY_W
		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_A
		|| keydata.key == MLX_KEY_D))
	{
		if (all->n_item == all->n_item_disable)
			mlx_close_window(all->win);
	}
	move4(keydata, all);
}

void	move4(mlx_key_data_t keydata, t_all *all)
{
	if (keydata.action != MLX_RELEASE && keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(all->win);
}

void	choose_and_disable_instance(t_all *all)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = 0;
	while (x <= all->x_fox)
	{
		y = 0;
		while ((y != all->y_fox || x != all->x_fox) && y < all->map->leny)
		{
			if (all->map->map[y][x] == 'C')
				count++;
			y++;
		}
		x++;
	}
	if (all->img->item->instances[count].enabled != 0)
	{
		all->img->item->instances[count].enabled = 0;
		all->n_item_disable += 1;
	}
}
