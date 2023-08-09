/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:57:38 by mbazirea          #+#    #+#             */
/*   Updated: 2022/12/11 10:15:21 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*tmp;
	void	*tmp2;

	if (!f || !del || !lst)
		return (NULL);
	final = NULL;
	while (lst)
	{
		tmp2 = f(lst->content);
		tmp = ft_lstnew(tmp2);
		if (!tmp)
		{
			free(tmp2);
			ft_lstclear(&final, del);
			return (NULL);
		}
		ft_lstadd_back(&final, tmp);
		lst = lst->next;
	}
	return (final);
}
