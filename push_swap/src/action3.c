/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 03:55:25 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/04 04:13:30 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack)
{
	unsigned int	i;
	unsigned int	tmp;

	if (stack->lena >= 2)
	{
		i = stack->lena;
		tmp = stack->a[stack->lena - 1];
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = tmp;
	}
	write(1, "rra\n", 4);
}

void	rra1(t_stack *stack)
{
	unsigned int	i;
	unsigned int	tmp;

	if (stack->lena >= 2)
	{
		i = stack->lena;
		tmp = stack->a[stack->lena - 1];
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = tmp;
	}
}

void	rrb(t_stack *stack)
{
	unsigned int	i;
	unsigned int	tmp;

	if (stack->lenb >= 2)
	{
		i = stack->lenb;
		tmp = stack->b[stack->lenb - 1];
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = tmp;
	}
	write(1, "rrb\n", 4);
}

void	rrb1(t_stack *stack)
{
	unsigned int	i;
	unsigned int	tmp;

	if (stack->lenb >= 2)
	{
		i = stack->lenb;
		tmp = stack->b[stack->lenb - 1];
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = tmp;
	}
}

void	rrr(t_stack *stack)
{
	rra1(stack);
	rrb1(stack);
	write(1, "rrr\n", 4);
}
