/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:59:18 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/09/09 18:39:21 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void		exit_input(t_env *e, SDL_Event event)
{
	(void)e;
	int		key;

	key = event.key.keysym.sym;
	if (key == SDLK_ESCAPE && event.type == SDL_KEYDOWN)
	{
		SDL_Quit();
		exit(0);
	}
}

static void		player_events(t_env *e, SDL_Event event, t_int mouse)
{
	int		key;
	t_int	curr_mouse;

	SDL_GetMouseState(&curr_mouse.x, &curr_mouse.y);
	key = event.key.keysym.sym;
	(key == SDLK_w && event.type == SDL_KEYDOWN) ? player_mvt(key, &e->player, *e->map) : 0;
	(key == SDLK_s && event.type == SDL_KEYDOWN) ? player_mvt(key, &e->player, *e->map) : 0;
	(key == SDLK_d && event.type == SDL_KEYDOWN) ? player_mvt(key, &e->player, *e->map) : 0;
	(key == SDLK_a && event.type == SDL_KEYDOWN) ? player_mvt(key, &e->player, *e->map) : 0;
//	(key == SDLK_q && event.type == SDL_KEYDOWN) ? player_rot(key, &e->player, mouse) : 0;
//	(key == SDLK_e && event.type == SDL_KEYDOWN) ? player_rot(key, &e->player, mouse) : 0;
	player_rot(key, &e->player, mouse.x - curr_mouse.x);
}

void			key_events(t_env *e)
{
	SDL_Event	event;
	t_int		mouse;

	SDL_GetMouseState(&mouse.x, &mouse.y);
	while (SDL_PollEvent(&event))
	{
//		menu_mvt(e, event);
		player_events(e, event, mouse);
		exit_input(e, event);
	}
}
