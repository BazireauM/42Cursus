/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:48:28 by mbazirea          #+#    #+#             */
/*   Updated: 2023/07/26 23:52:55 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main2(t_all *all, t_map *map, char *argv[]);
int	test_map_main(t_map *map, t_all *all);

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_all	*all;

	if (argc != 2)
	{
		ft_printf("1 argument requiered\n");
		return (1);
	}
	if (test_name_file(argv[1]) == 1)
	{
		ft_printf("error files\n");
		return (1);
	}
	all = malloc(sizeof(t_all) * 1);
	if (!all)
	{
		ft_printf("error\n");
		return (1);
	}
	map = malloc(sizeof(t_map) * 1);
	if (test_map_main(map, all) == 1)
		return (1);
	if (main2(all, map, argv) == 1)
		return (1);
	return (0);
}

int	test_map_main(t_map *map, t_all *all)
{
	if (!map)
	{
		ft_printf("error\n");
		free(all);
		return (1);
	}
	return (0);
}

int	main2(t_all *all, t_map *map, char *argv[])
{
	map->map = parssing(argv[1]);
	if (!map->map)
	{
		ft_printf("error\n");
		free(map);
		free(all);
		return (1);
	}
	if (test_map(map) == 1)
	{
		free_map(map->map);
		free(map);
		free(all);
		return (1);
	}
	init(map, all);
	mlx_key_hook(all->win, &move, all);
	mlx_loop(all->win);
	final_free(all);
	return (0);
}
