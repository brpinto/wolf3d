/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:03:51 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 16:58:11 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *beginlist;
	t_list *currentlist;

	if (!lst || !f)
		return (NULL);
	beginlist = f(lst);
	currentlist = beginlist;
	while (lst->next)
	{
		lst = lst->next;
		currentlist->next = f(lst);
		currentlist = currentlist->next;
	}
	return (beginlist);
}
