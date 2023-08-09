/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:44:32 by mbazirea          #+#    #+#             */
/*   Updated: 2023/07/26 20:33:01 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*init_img(mlx_t *win)
{
	t_img	*img;

	img = malloc(sizeof(t_img) * 1);
	if (img == NULL)
		return (NULL);
	img->doort = mlx_load_png("sprite/Door.png");
	img->door = mlx_new_image(win, 20, 20);
	img->door = mlx_texture_to_image(win, img->doort);
	img->foxt = mlx_load_png("sprite/Fox.png");
	img->fox = mlx_new_image(win, 20, 20);
	img->fox = mlx_texture_to_image(win, img->foxt);
	img->wallt = mlx_load_png("sprite/Wall.png");
	img->wall = mlx_new_image(win, 20, 20);
	img->wall = mlx_texture_to_image(win, img->wallt);
	img->itemt = mlx_load_png("sprite/item.png");
	img->item = mlx_new_image(win, 20, 20);
	img->item = mlx_texture_to_image(win, img->itemt);
	img->nonet = mlx_load_png("sprite/none.png");
	img->none = mlx_new_image(win, 20, 20);
	img->none = mlx_texture_to_image(win, img->nonet);
	return (img);
}

void	first_print(mlx_t *win, t_img *img, t_map *map)
{
	t_xy	xy;

	xy.x = 0;
	while (xy.x < map->lenx)
	{
		xy.y = 0;
		while (xy.y < map->leny)
		{
			chose_and_print(map->map[xy.y][xy.x], img, win, &xy);
			xy.y += 1;
		}
		xy.x += 1;
	}
	xy.x = 0;
	while (xy.x < map->lenx)
	{
		xy.y = 0;
		while (xy.y < map->leny)
		{
			if (map->map[xy.y][xy.x] == 'P')
				mlx_image_to_window(win, img->fox, xy.x * 20, xy.y * 20);
			xy.y += 1;
		}
		xy.x += 1;
	}
}

void	chose_and_print(char c, t_img *img, mlx_t *win, t_xy *xy)
{
	if (c == '1')
		mlx_image_to_window(win, img->wall, xy->x * 20, xy->y * 20);
	else if (c == '0')
		mlx_image_to_window(win, img->none, xy->x * 20, xy->y * 20);
	else if (c == 'C')
	{
		mlx_image_to_window(win, img->none, xy->x * 20, xy->y * 20);
		mlx_image_to_window(win, img->item, xy->x * 20, xy->y * 20);
	}
	else if (c == 'E')
		mlx_image_to_window(win, img->door, xy->x * 20, xy->y * 20);
	else if (c == 'P')
		mlx_image_to_window(win, img->none, xy->x * 20, xy->y * 20);
}
