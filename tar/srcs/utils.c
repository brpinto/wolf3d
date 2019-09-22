/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:08:52 by brpinto           #+#    #+#             */
/*   Updated: 2019/09/09 18:56:42 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_int	convert_to_map(int x, int y)
{
	t_int	index;

	index.x = x / CUBE_SIZE;
	index.y = y / CUBE_SIZE;
	return (index);
}

float	convert_to_rad(float angle)
{
	angle *= M_PI / 180;
	return(angle);
}

float	angle_period(float angle)
{
	while (angle < 0)
		angle = angle + 360;
	while (angle >= 360)
		angle = angle - 360;
	return (angle);
}

void	bresenham(t_env *e, t_cam *cam, t_float next_pos, int i)
{
	t_float		delta;
	t_int		delta_s;
	t_float		current;
	float		delta_err;
	float		delta_e2;

	current.x = cam->pos.x;
	current.y = cam->pos.y;
	delta.x = fabsf(next_pos.x - cam->pos.x);
	delta_s.x = (cam->pos.x < next_pos.x ? 1 : -1);
	delta.y = fabsf(next_pos.y - cam->pos.y);
	delta_s.y = (cam->pos.y < next_pos.y ? 1 : -1);
	delta_err = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (1)
	{
		if (ray_collision(current.x, current.y, e->map) == TRUE)
		{
			draw_wall(e, cam, current, i);
			break ;
		}
//		draw_fov(e->win.renderer, current);
		delta_e2 = delta_err;
		if (delta_e2 > -delta.x)
		{
			delta_err -= delta.y;
			current.x += delta_s.x;
		}
		if (delta_e2 < delta.y)
		{
			delta_err += delta.x;
			current.y += delta_s.y;
		}
	}
}
