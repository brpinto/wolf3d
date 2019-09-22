/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:34:06 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:38:12 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(const char *s)
{
	size_t start;
	size_t len;

	if (s)
	{
		start = 0;
		len = ft_strlen(s) - 1;
		while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
			start++;
		if (s[start] == '\0')
			return (ft_strdup(s + start));
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			len--;
		return (ft_strsub(s, start, len - start + 1));
	}
	return (0);
}
