/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:00:00 by mbazirea          #+#    #+#             */
/*   Updated: 2022/11/05 16:30:27 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*test;
	char	*null;
	size_t	i;

	test = malloc (count * size);
	if (!test)
		return (NULL);
	null = (char *) test;
	i = 0;
	while (i < count * size)
	{
		null[i] = '\0';
		i++;
	}
	return (test);
}
