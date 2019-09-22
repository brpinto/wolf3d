/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:47:56 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/06 16:54:34 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_nblen(int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;

	res = NULL;
	len = ft_nblen(n);
	if (n != -2147483648)
	{
		if (!(res = (char*)malloc(sizeof(char) * len + 1)))
			return (0);
		if (n < 0)
		{
			res[0] = '-';
			n = -n;
		}
		if (n == 0)
			res[0] = '0';
		res[len] = '\0';
		while (n)
		{
			res[--len] = n % 10 + '0';
			n = n / 10;
		}
		return (res);
	}
	return (ft_strdup("-2147483648"));
}
