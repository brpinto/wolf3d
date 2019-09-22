/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:28:22 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:30:47 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	size_t			slen;

	if (s && f)
	{
		i = 0;
		slen = ft_strlen(s);
		str = NULL;
		if (!(str = (char*)malloc(sizeof(char) * slen + 1)))
			return (0);
		while (i < slen)
		{
			str[i] = (f(i, (char)s[i]));
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
