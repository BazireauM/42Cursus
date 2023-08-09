/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:19:06 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/05 17:17:59 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *m, int c, size_t size)
{
	size_t	i;
	char	*m2;

	m2 = (char *) m;
	i = 0;
	while (i < size)
	{
		if (m2[i] == (char) c)
			return (&m2[i]);
		i++;
	}
	return (0);
}
