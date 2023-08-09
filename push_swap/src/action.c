/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 02:18:05 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/05 12:55:19 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack	*stack)
{
	unsigned int	tmp;

	if (stack->lena >= 2)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack	*stack)
{
	unsigned int	tmp;

	if (stack->lenb >= 2)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack	*stack)
{
	unsigned int	tmp;

	if (stack->lena >= 2)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	if (stack->lenb >= 2)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
	write(1, "ss\n", 3);
}

void	pb(t_stack	*stack)
{
	unsigned int	i;

	if (stack->lena >= 1)
	{
		i = stack->lenb;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		i = 0;
		while (i < stack->lena - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->lena--;
		stack->lenb++;
	}
	write(1, "pb\n", 3);
}

void	pa(t_stack	*stack)
{
	unsigned int	i;

	if (stack->lenb >= 1)
	{
		i = stack->lena;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		while (i < stack->lenb - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->lenb--;
		stack->lena++;
	}
	write(1, "pa\n", 3);
}
