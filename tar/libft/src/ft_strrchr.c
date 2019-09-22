/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:21:41 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:33:16 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t slen;

	slen = ft_strlen(s);
	while (slen)
	{
		if (s[slen] == (char)c)
			return ((char*)s + slen);
		slen--;
	}
	if (s[0] == (char)c)
		return ((char*)s);
	return (0);
}
