/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:13:14 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:28:14 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *src)
{
	size_t		i;
	char		*dest;
	size_t		length;

	i = 0;
	dest = NULL;
	length = ft_strlen(src);
	if (!(dest = (char*)malloc(sizeof(char) * length + 1)))
		return (0);
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
