/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_new_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:16:58 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/07 02:25:06 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		**ft_tab_new_int(size_t x, size_t y)
{
	int		**tab;
	size_t	i;

	i = 0;
	tab = NULL;
	if (!(tab = (int**)ft_memalloc(sizeof(int*) * y)))
		return (NULL);
	while (i < y)
	{
		if (!(tab[i] = (int*)ft_memalloc(sizeof(int) * x)))
			return (NULL);
		i++;
	}
	return (tab);
}
