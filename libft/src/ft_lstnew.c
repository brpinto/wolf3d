/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:09:09 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 16:59:00 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*newlist;

	newlist = NULL;
	if (!(newlist = (t_list*)malloc(sizeof(*newlist))))
		return (NULL);
	if (content)
	{
		if (!(newlist->content = (void*)malloc(sizeof(void) * (content_size))))
			return (NULL);
		ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	else
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	newlist->next = NULL;
	return (newlist);
}
