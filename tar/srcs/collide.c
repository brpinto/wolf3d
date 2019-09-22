/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:58:25 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/08/20 17:16:05 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		ray_collision(int x, int y, t_map *map)
{
	t_int	index;

	index = convert_to_map(x, y);
	if (map->map[index.y][index.x] == 1)
		return (TRUE);
	return (FALSE);
}
