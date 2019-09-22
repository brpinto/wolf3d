/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:35:42 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/07 02:34:43 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void *alloc;

	alloc = NULL;
	if (!(alloc = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(alloc, size);
	return (alloc);
}
