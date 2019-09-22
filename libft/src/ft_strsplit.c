/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:08:04 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 17:33:35 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t		ft_countwords(const char *s, char c)
{
	int		i;
	size_t	nbwords;

	i = 0;
	nbwords = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbwords++;
		i++;
	}
	return (nbwords);
}

static char			**ft_strtotab(const char *s, char c, char **result)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			j = i + 1;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			result[k] = ft_strsub(s, (unsigned int)j, i - j + 1);
			k++;
			j = 0;
		}
		i++;
	}
	result[k] = 0;
	return (result);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**result;
	size_t	nbwords;
	size_t	i;

	i = 0;
	result = NULL;
	if (!s || !c)
		return (0);
	nbwords = ft_countwords(s, c);
	if (!(result = (char**)malloc(sizeof(char*) * nbwords + 1)))
		return (0);
	if (nbwords == 0)
	{
		result[0] = NULL;
		return (result);
	}
	result = ft_strtotab(s, c, result);
	return (result);
}
