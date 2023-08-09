/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:22:39 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/04 02:08:52 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(char *big_str)
{
	t_stack	*stack;
	int		len;
	char	**big_str_split;
	int		i;

	i = 0;
	big_str_split = ft_split(big_str, ' ');
	free(big_str);
	while (big_str_split[i])
		i++;
	len = i;
	if (test_int(big_str_split) == 1)
	{
		free_ft_split(big_str_split);
		return (NULL);
	}
	stack = init_stack2(big_str_split, len);
	return (stack);
}

t_stack	*init_stack2(char **big_str_split, int len)
{
	int		i;
	t_stack	*stack;
	int		*a;

	i = 0;
	a = malloc(sizeof(int) * len);
	if (a == NULL)
	{
		free_ft_split(big_str_split);
		return (NULL);
	}
	while (big_str_split[i])
	{
		a[i] = ft_atoi(big_str_split[i]);
		i++;
	}
	free_ft_split(big_str_split);
	if (test_duplicate(a, len) == 1)
	{
		free(a);
		return (NULL);
	}
	stack = init_stack3(a, len);
	return (stack);
}

t_stack	*init_stack3(int *a, int len)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack) * 1);
	if (stack == NULL)
	{
		free(a);
		return (NULL);
	}
	stack->a = malloc(sizeof(unsigned int) * len);
	if (stack->a == NULL)
	{
		free(a);
		free(stack);
		return (NULL);
	}
	stack = init_stack4(stack, a, len);
	return (stack);
}

t_stack	*init_stack4(t_stack *stack, int *a, int len)
{
	int	i;

	i = 0;
	stack->b = malloc(sizeof(unsigned int) * len);
	if (stack->b == NULL)
	{
		free(a);
		free(stack->a);
		free(stack);
		return (NULL);
	}
	stack->len = len;
	stack->lena = len;
	stack->lenb = 0;
	while ((unsigned int)i < stack->lena)
	{
		stack->a[i] = rank(a, i, len);
		i++;
	}
	free(a);
	return (stack);
}
