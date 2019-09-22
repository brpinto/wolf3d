/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:34:59 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/09/16 16:29:58 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		cast_single_ray(t_env *e, t_cam *cam, int i)
{
	t_float		next_pos;
	float		rad_angle;

	rad_angle = convert_to_rad(cam->curr_angle);
	next_pos.x = cam->pos.x + (40 * cos(rad_angle));
	next_pos.y = cam->pos.y - (40 * sin(rad_angle));
	bresenham(e, cam, next_pos, i);
}

void		raycast(t_env *e, t_win *win, t_cam *cam)
{
	int			i;
	float		angle_max;
	float		angle_step;

	i = 0;
	cam->curr_angle = cam->angle + (ANGLE / 2);
	angle_max = cam->angle - (ANGLE / 2);
	angle_step = ANGLE / win->w;
	while (++i < win->w)
	{
		cast_single_ray(e, cam, i);
		cam->curr_angle -= angle_step;
	}
}
