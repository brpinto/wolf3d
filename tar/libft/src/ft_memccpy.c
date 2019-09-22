/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:06:25 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:01:30 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sourc;

	i = 0;
	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = sourc[i];
		if (sourc[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
