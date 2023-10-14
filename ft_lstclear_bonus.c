/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdamian- < fdamian-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:52:42 by fdamian-          #+#    #+#             */
/*   Updated: 2023/10/14 23:09:52 by fdamian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		aux = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = aux;
	}
	*lst = NULL;
}
