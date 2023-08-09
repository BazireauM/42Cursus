/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:48:18 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/05 14:39:06 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	int		b;
	char	*final;

	if (start > ft_strlen(s))
	{
		final = malloc(sizeof(char));
		if (!final)
			return (NULL);
		final[0] = '\0';
		return (final);
	}
	if (ft_strlen(s) >= len && start + len != ft_strlen(s) + 1
		&& start + len != ft_strlen(s) + 2)
		final = malloc(sizeof(char) * ((int) len + 1));
	else
		final = malloc(sizeof(char) * ((int) ft_strlen(s) - start + 1));
	if (!final)
		return (NULL);
	a = 0;
	b = start;
	while (s[b] && a < len)
		final[a++] = s[b++];
	final[a] = '\0';
	return (final);
}
