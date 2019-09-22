/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:08:10 by brounch           #+#    #+#             */
/*   Updated: 2019/09/09 18:56:30 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	draw_wall(t_env *e, t_cam *cam, t_float current, int i)
{
	int		w_height;

	current.x -= cam->pos.x;
	current.y -= cam->pos.y;
	w_height = CUBE_SIZE  / (sqrt(pow(current.x, 2) + pow(current.y, 2)) * cos(convert_to_rad(fabsf(cam->curr_angle - cam->angle)))) * VIEW_DIST;
	SDL_SetRenderDrawColor(e->win.renderer, ((abs((int)cam->curr_angle)) * 4) % 255, 0, 255, 255);
	SDL_RenderDrawLine(e->win.renderer, i, (e->win.h / 2) - w_height, i, (e->win.h / 2) + w_height);
}

void	run(t_env *e)
{
	Uint32	current;
	Uint32	new;

	while (TRUE)
	{
		current = SDL_GetTicks();
		raycast(e, &e->win, &e->player.cam);
//		disp_player(e);
//		display_minimap(e);
		key_events(e);
		SDL_RenderPresent(e->win.renderer);
		SDL_SetRenderDrawColor(e->win.renderer, 0, 0, 0, 255);
		SDL_RenderClear(e->win.renderer);
		new = SDL_GetTicks();
		new -= current;
		(new < FPS_TARGET) ? SDL_Delay((FPS_TARGET) - new) : 0;
	}
}
