/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdamian- < fdamian-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:34:46 by fdamian-          #+#    #+#             */
/*   Updated: 2023/10/24 21:26:11 by fdamian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*s;
	void	*content;

	p = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		s = ft_lstnew(content);
		if (!s)
		{
			del(content);
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, s);
		lst = lst->next;
	}
	return (p);
}
