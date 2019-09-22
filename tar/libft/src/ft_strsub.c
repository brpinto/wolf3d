/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:25:19 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:37:46 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *str;

	if (s)
	{
		str = NULL;
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (0);
		ft_strncpy(str, s + start, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
