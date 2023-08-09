/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:38:36 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/05 13:02:00 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	start(char const *s1, char const *set)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	c = 1;
	while (c && s1[a])
	{
		b = 0;
		c = 0;
		while (set[b])
		{
			if (s1[a] == set[b])
				c = 1;
			b++;
		}
		if (c == 1)
			a++;
	}
	return (a);
}

int	end(char const *s1, char const *set)
{
	int	a;
	int	b;
	int	c;

	a = ft_strlen(s1) - 1;
	c = 1;
	while (c && a >= 0)
	{
		c = 0;
		b = 0;
		while (set[b])
		{
			if (s1[a] == set[b])
				c = 1;
			b++;
		}
		if (c == 1)
			a--;
	}
	a = ft_strlen(s1) - a - 1;
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start2;
	int		end2;
	int		a;
	char	*final;

	start2 = start(s1, set);
	end2 = end(s1, set);
	if (start2 == (int) ft_strlen(s1))
	{
		final = malloc(1);
		if (!final)
			return (NULL);
		final[0] = '\0';
		return (final);
	}
	final = malloc(sizeof(char) * ft_strlen(s1) - start2 - end2 + 1);
	if (!final)
		return (NULL);
	a = 0;
	while (start2 < (int) ft_strlen(s1) - end2)
		final[a++] = s1[start2++];
	final[a] = '\0';
	return (final);
}
