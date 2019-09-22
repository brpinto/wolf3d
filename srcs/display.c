/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:08:10 by brounch           #+#    #+#             */
/*   Updated: 2019/09/18 15:52:40 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	draw_wall(t_env *e, t_cam *cam, t_float current, int i)
{
	float	w_height;
	t_int	start;
	t_int	end;

	current.x -= cam->pos.x;
	current.y -= cam->pos.y;
	w_height = CUBE_SIZE  * VIEW_DIST / (sqrtf(powf(current.x, 2) + powf(current.y, 2)) * cosf(convert_to_rad(fabsf(cam->curr_angle - cam->angle))));
//	SDL_SetRenderDrawColor(e->win.renderer, ((abs((int)cam->curr_angle)) * 4) % 255, 0, 255, 255);
	start.x = i;
	start.y = (e->win.h / 2) - round(w_height);
	end.x = i;
	end.y = (e->win.h / 2) + round(w_height);
	bresenham2(e, e->win.renderer, start, end);
}

/*void	draw_wall(t_env *e, t_cam *cam, t_float current, int i)
{
	float	w_height;

	current.x -= cam->pos.x;
	current.y -= cam->pos.y;
	w_height = CUBE_SIZE  * VIEW_DIST / (sqrtf(powf(current.x, 2) + powf(current.y, 2)) * cosf(convert_to_rad(fabsf(cam->curr_angle - cam->angle))));
//	SDL_SetRenderDrawColor(e->win.renderer, ((abs((int)cam->curr_angle)) * 4) % 255, 0, 255, 255);
	SDL_RenderDrawLine(e->win.renderer, i, (e->win.h / 2) - round(w_height), i, (e->win.h / 2) + round(w_height));
}*/

void	run(t_env *e)
{
	Uint32	current;
	Uint32	new;

	while (TRUE)
	{
		current = SDL_GetTicks();
//		(ft_strcmp(e->editor, "editor") == 0) ? run_editor(e) : 0;
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
