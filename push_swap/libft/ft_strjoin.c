/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:18:42 by mbazirea          #+#    #+#             */
/*   Updated: 2023/06/02 04:41:22 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*final;

	a = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(sizeof(char) * a + 1);
	if (!final)
		return (NULL);
	a = 0;
	b = 0;
	while (s1[b])
	{
		final[a] = s1[b];
		b++;
		a++;
	}
	b = 0;
	while (s2[b])
	{
		final[a] = s2[b];
		b++;
		a++;
	}
	final[a] = '\0';
	return (final);
}
