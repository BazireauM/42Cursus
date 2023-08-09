/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:31:19 by mbazirea          #+#    #+#             */
/*   Updated: 2022/12/11 09:48:15 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst && del)
	{
		tmp2 = *lst;
		while (tmp2)
		{
			tmp = tmp2->next;
			ft_lstdelone(tmp2, del);
			tmp2 = tmp;
		}
		*lst = NULL;
	}
}
