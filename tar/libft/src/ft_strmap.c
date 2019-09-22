/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:27:20 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:30:33 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	slen;
	size_t	i;
	char	*str;

	if (s && f)
	{
		slen = ft_strlen(s);
		i = 0;
		str = NULL;
		if (!(str = (char*)malloc(sizeof(char) * slen + 1)))
			return (0);
		while (i < slen)
		{
			str[i] = f((char)s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
