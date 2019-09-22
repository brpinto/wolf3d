/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:05:41 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/06/26 15:06:45 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	print_tab(int **tab, int w, int h)
{
	int i;
	int j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			ft_putnbr(tab[j][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
