/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:04:56 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/09 11:33:51 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	algo(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	if (test_sort(stack) == 1)
		return (1);
	if (stack->len <= 5)
		return (sort_small(stack));
	while (!test_sort(stack))
	{
		put_in_b(stack, i);
		put_in_a(stack);
		i++;
	}
	return (test_sort(stack));
}

int	sort_small(t_stack *stack)
{
	while (stack->lena > 3)
	{
		pb(stack);
	}
	sort_3(stack);
	if (stack->lenb == 2)
	{
		sort_4(stack);
		sort_5(stack);
	}
	if (stack->lenb == 1)
		sort_4(stack);
	return (1);
}

void	sort_4(t_stack *stack)
{
	int	a;

	a = rank_simple(stack);
	if (a == 0)
		pa(stack);
	else if (a == 1)
	{
		pa(stack);
		sa(stack);
	}
	else if (a == 2)
	{
		ra(stack);
		pa(stack);
		sa(stack);
		rra(stack);
	}
	else if (a == 3)
	{
		pa(stack);
		ra(stack);
	}
}

void	sort_3(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] < stack->a[2])
		sa(stack);
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ra(stack);
		sa(stack);
	}
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] < stack->a[0])
		rra(stack);
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[2] > stack->a[0])
	{
		rra(stack);
		sa(stack);
	}
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] < stack->a[2])
		ra(stack);
}

unsigned int	rank_simple(t_stack *stack)
{
	int				count;
	unsigned int	b;

	count = stack->lena;
	b = 0;
	while (b < stack->lena)
	{
		if (stack->b[0] < stack->a[b])
			count--;
		b++;
	}
	return (count);
}
