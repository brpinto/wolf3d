/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:21:20 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 16:57:24 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*currentlist;
	t_list		*nextlist;

	currentlist = *alst;
	while (currentlist)
	{
		nextlist = currentlist->next;
		del(currentlist->content, currentlist->content_size);
		free(currentlist);
		currentlist = nextlist;
	}
	*alst = NULL;
}
