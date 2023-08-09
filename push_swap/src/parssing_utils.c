/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 03:48:56 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/07 09:59:16 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	test_input_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != ' ')
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (str[i - 1] != ' ' || !ft_isdigit(str[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

char	*big_strjoin(int argc, char *argv[])
{
	char	*big_str;
	int		i;

	i = 1;
	big_str = malloc(sizeof(char) * 2);
	if (big_str == NULL)
		return (NULL);
	big_str[0] = ' ';
	big_str[1] = '\0';
	while (i < argc)
	{
		big_str = big_strjoin2(big_str, i, argv);
		if (big_str == NULL)
			return (NULL);
		i++;
	}
	return (big_str);
}

char	*big_strjoin2(char *big_str, int i, char *argv[])
{
	char	*big_str2;

	big_str2 = ft_strjoin(big_str, " ");
	if (big_str2 == NULL)
	{
		free(big_str);
		return (NULL);
	}
	free(big_str);
	big_str = big_str2;
	big_str2 = ft_strjoin(big_str, argv[i]);
	if (big_str2 == NULL)
	{
		free(big_str);
		return (NULL);
	}
	free(big_str);
	big_str = big_str2;
	return (big_str);
}

int	test_int(char **big_str_split)
{
	int	i;

	i = 0;
	while (big_str_split[i])
	{
		if (is_int(big_str_split[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

unsigned int	rank(int *a, int i, int len)
{
	int	count;
	int	b;

	count = len - 1;
	b = 0;
	while (b < len)
	{
		if (a[i] < a[b])
			count--;
		b++;
	}
	return (count);
}
