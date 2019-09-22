/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:11:16 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:28:34 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strequ(const char *s1, const char *s2)
{
	if (s1 && s2)
	{
		if (ft_strcmp((char*)s1, (char*)s2) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
