/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:28:12 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:37:09 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_lensplit(const char *s, char c)
{
	int		i;
	size_t	splitlen;

	i = 0;
	splitlen = 0;
	while (s[i])
	{
		if (s[i] != c)
			splitlen++;
		i++;
	}
	return (splitlen);
}

char			*ft_strsplit_to_str(const char *s, char c)
{
	char	*result;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = NULL;
	if (!s || !c)
		return (NULL);
	len = ft_lensplit(s, c);
	result = (char*)ft_memalloc(len + 1);
	while (s[i])
	{
		if (s[i] != c)
			result[j++] = s[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}
