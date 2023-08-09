/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 03:26:34 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/04 03:55:15 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack)
{
	unsigned int	i;
	unsigned int	tmp;

	if (stack->lena >= 2)
	{
		i = 0;
		tmp = stack->a[0];
		while (i < stack->lena - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = tmp;
	}
	write(1, "ra\n", 3);
}

void	ra1(t_stack *stack)
{
	unsigned int	i;
	unsigned int	tmp;

	if (stack->lena >= 2)
	{
		i = 0;
		tmp = stack->a[0];
		while (i < stack->lena - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = tmp;
	}
}

void	rb(t_stack *stack)
{
	unsigned int	i;
	unsigned int	tmp;

	if (stack->lenb >= 2)
	{
		i = 0;
		tmp = stack->b[0];
		while (i < stack->lenb - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = tmp;
	}
	write(1, "rb\n", 3);
}

void	rb1(t_stack *stack)
{
	unsigned int	i;
	unsigned int	tmp;

	if (stack->lenb >= 2)
	{
		i = 0;
		tmp = stack->b[0];
		while (i < stack->lenb - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = tmp;
	}
}

void	rr(t_stack *stack)
{
	ra1(stack);
	rb1(stack);
	write(1, "rr\n", 3);
}
