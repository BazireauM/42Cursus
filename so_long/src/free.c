/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:31:48 by mbazirea          #+#    #+#             */
/*   Updated: 2023/07/26 23:30:16 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	free_struct_map(t_map *map)
{
	free_map(map->map);
	free(map);
}

void	final_free(t_all *all)
{
	free_map(all->map->map);
	free(all->map);
	mlx_delete_texture(all->img->doort);
	mlx_delete_texture(all->img->wallt);
	mlx_delete_texture(all->img->foxt);
	mlx_delete_texture(all->img->itemt);
	mlx_delete_texture(all->img->nonet);
	mlx_delete_image(all->win, all->img->door);
	mlx_delete_image(all->win, all->img->wall);
	mlx_delete_image(all->win, all->img->fox);
	mlx_delete_image(all->win, all->img->item);
	mlx_delete_image(all->win, all->img->none);
	mlx_terminate(all->win);
	free(all->img);
	free(all);
}
