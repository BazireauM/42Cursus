/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:10:26 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/05 17:07:21 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char	*src2;
	char	*dst2;
	size_t	i;

	src2 = (char *) src;
	dst2 = (char *) dst;
	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < size)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
