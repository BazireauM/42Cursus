/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 03:46:20 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/07 10:26:00 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*parssing(int argc, char *argv[])
{
	char			*big_str;
	t_stack			*stack;

	if (argc < 2)
		return (NULL);
	big_str = big_strjoin(argc, argv);
	if (big_str == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	if (test_input_valid(big_str) == 1)
	{
		write(2, "Error\n", 6);
		free(big_str);
		return (NULL);
	}
	stack = init_stack(big_str);
	if (stack == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stack);
}
