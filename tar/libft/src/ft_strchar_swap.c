/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:56:25 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:26:20 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchar_swap(const char *s, char c, char b)
{
	char	*result;
	size_t	len;
	int		i;

	i = 0;
	result = NULL;
	if (!s || !c || !s)
		return (NULL);
	len = ft_strlen(s);
	result = (char*)ft_memalloc(len + 1);
	while (s[i])
	{
		if (s[i] == c)
			result[i] = b;
		else
			result[i] = s[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}
