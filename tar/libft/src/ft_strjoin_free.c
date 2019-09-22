/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:26:24 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:29:38 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_free(const char *s1, const char *s2, int n)
{
	char *res;

	res = NULL;
	res = ft_strjoin(s1, s2);
	if (n == 1)
		free((char*)s1);
	else if (n == 2)
		free((char*)s2);
	else if (n == 3)
	{
		free((char*)s1);
		free((char*)s2);
	}
	return (res);
}
