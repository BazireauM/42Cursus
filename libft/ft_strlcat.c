/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:48:36 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/03 12:35:49 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	size_dst;
	size_t	size_src;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	i = size_dst;
	c = 0;
	while (i < size - 1 && size > 0 && src[c])
	{
		dst[i] = src[c];
		i++;
		c++;
	}
	if (size > 0 && size_dst < size -1)
		dst[i] = '\0';
	if (size < size_dst)
		return (size + size_src);
	return (size_src + size_dst);
}
