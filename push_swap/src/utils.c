/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 02:19:29 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/05 12:15:43 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

void	free_ft_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

long long	ft_atoi_long_long(const char *s)
{
	int			i;
	long long	mul;
	long long	final;

	i = 0;
	mul = 1;
	final = 0;
	while (s[i] != '\0' && (s[i] == '\f' || s[i] == '\r' || s[i] == ' '
			|| s[i] == '\t' || s[i] == '\v' || s[i] == '\n'))
		i++;
	if (s[i] == '-')
	{
		mul = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		final = final * 10 + s[i] - 48;
		i++;
	}
	final *= mul;
	return (final);
}

int	is_int(char *nb)
{
	if (ft_atoi_long_long(nb) > 2147483647
		|| ft_atoi_long_long(nb) < -2147483648)
		return (1);
	return (0);
}

int	test_duplicate(int *a, int len)
{
	int	i;
	int	b;
	int	count;

	i = 0;
	while (i < len)
	{
		b = i;
		count = 0;
		while (b < len)
		{
			if (a[i] == a[b])
				count++;
			b++;
		}
		if (count >= 2)
			return (1);
		i++;
	}
	return (0);
}
