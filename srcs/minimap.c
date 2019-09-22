/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:13:14 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/09/09 17:02:52 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		draw_fov(SDL_Renderer *renderer, t_float current)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(renderer, round(current.x), round(current.y));
}

void		display_minimap(t_env *e)
{
	int i;
	int j;

	e->win.disp_rect.x = 0;
	e->win.disp_rect.y = 0;
	e->win.disp_rect.w = CUBE_SIZE;
	e->win.disp_rect.h = CUBE_SIZE;
	i = 0;
	while (i < e->map->h)
	{
		j = 0;
		e->win.disp_rect.x = 0;
		while (j < e->map->w)
		{
			if (e->map->map[i][j] == 1)
			{
				SDL_SetRenderDrawColor(e->win.renderer, 0, 0, 255, 255);
				SDL_RenderFillRect(e->win.renderer, &(e->win.disp_rect));
			}
			SDL_SetRenderDrawBlendMode(e->win.renderer, SDL_BLENDMODE_BLEND);
			SDL_SetRenderDrawColor(e->win.renderer, 255, 255, 255, 125);
			SDL_RenderDrawRect(e->win.renderer, &(e->win.disp_rect));
			e->win.disp_rect.x += CUBE_SIZE;
			j++;
		}
		e->win.disp_rect.y += CUBE_SIZE;
		i++;
	}
	disp_player(e);
}
