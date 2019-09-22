/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:30:25 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:30:00 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_length;

	dest_length = ft_strlen(dest);
	if (size <= dest_length)
		return (ft_strlen(src) + size);
	else
	{
		ft_strncat(dest, src, size - dest_length - 1);
		return (ft_strlen(src) + dest_length);
	}
}
