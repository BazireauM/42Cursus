/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:38:29 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/02 16:49:17 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	char	*src2;
	char	*dst2;

	src2 = (char *) src;
	dst2 = (char *) dst;
	if (src < dst)
	{
		while (size-- > 0)
			dst2[size] = src2[size];
	}
	else
		ft_memcpy(dst, src, (int) size);
	return (dst);
}
