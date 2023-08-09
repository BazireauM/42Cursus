/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:36:17 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/05 17:18:24 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	unsigned char	*a1;
	unsigned char	*a2;
	int				i;

	a1 = (unsigned char *) p1;
	a2 = (unsigned char *) p2;
	i = 0;
	while (size > 0)
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		size--;
		i++;
	}
	return (0);
}
