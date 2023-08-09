/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:00:26 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/05 17:19:05 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *) s1);
	while (i < n && s1[i])
	{
		if (s1[i] == s2[0])
		{
			a = 0;
			while (s1[i + a] == s2[a] && s1[i + a] && s2[a] && i + a < n)
				a++;
			if (s2[a] == '\0')
				return ((char *) &s1[i]);
		}
		i++;
	}
	return (NULL);
}
