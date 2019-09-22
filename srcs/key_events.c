/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:59:18 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/09/17 13:35:51 by brpinto          ###   ########.fr       */
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

void			copy_keyboard_state(Uint8 *keyb_curr, Uint8 keyb_prev[283])
{
	int i;

	i = 0;
	while (i < 284)
	{
		keyb_prev[i] = keyb_curr[i];
		i++;
	}
}

int				compare_keyb(t_win *win, int key)
{
	if (win->keyb_curr[key])
		return (1);
	return (0);
}

static void		player_events(t_env *e)
{
	(compare_keyb(&e->win, SDL_SCANCODE_W)) ? player_mvt(SDL_SCANCODE_W, &e->player, *e->map) : 0;
	(compare_keyb(&e->win, SDL_SCANCODE_A)) ? player_mvt(SDL_SCANCODE_A, &e->player, *e->map) : 0;
	(compare_keyb(&e->win, SDL_SCANCODE_S)) ? player_mvt(SDL_SCANCODE_S, &e->player, *e->map) : 0;
	(compare_keyb(&e->win, SDL_SCANCODE_D)) ? player_mvt(SDL_SCANCODE_D, &e->player, *e->map) : 0;
	(compare_keyb(&e->win, SDL_SCANCODE_Q)) ? player_rot(SDL_SCANCODE_Q, &e->player) : 0;
	(compare_keyb(&e->win, SDL_SCANCODE_E)) ? player_rot(SDL_SCANCODE_E, &e->player) : 0;
/*
	(key == SDLK_w && event.type == SDL_KEYDOWN) ? player_mvt(key, &e->player, *e->map) : 0;
	(key == SDLK_d && event.type == SDL_KEYDOWN) ? player_mvt(key, &e->player, *e->map) : 0;
	(key == SDLK_s && event.type == SDL_KEYDOWN) ? player_mvt(key, &e->player, *e->map) : 0;
	(key == SDLK_a && event.type == SDL_KEYDOWN) ? player_mvt(key, &e->player, *e->map) : 0;
	(key == SDLK_w && event.type == SDL_KEYUP) ? player_mvt2(key, &e->player) : 0;
	(key == SDLK_d && event.type == SDL_KEYUP) ? player_mvt2(key, &e->player) : 0;
	(key == SDLK_s && event.type == SDL_KEYUP) ? player_mvt2(key, &e->player) : 0;
	(key == SDLK_a && event.type == SDL_KEYUP) ? player_mvt2(key, &e->player) : 0;
	(key == SDLK_q) ? player_rot(key, &e->player) : 0;
	(key == SDLK_e) ? player_rot(key, &e->player) : 0;
	(key == SDLK_q && event.type == SDL_KEYDOWN) ? player_rot(key, &e->player) : 0;
	(key == SDLK_e && event.type == SDL_KEYDOWN) ? player_rot(key, &e->player) : 0;
	*/
}

static void		mouse_events(t_env *e)
{
	t_int	curr_mouse;

	SDL_SetRelativeMouseMode(SDL_TRUE);
	SDL_GetRelativeMouseState(&curr_mouse.x, &curr_mouse.y);
	e->player.cam.angle = angle_period(e->player.cam.angle - (curr_mouse.x / e->player.cam.sensitivity));
}

/*static void		draw_map(t_env *e, SDL_Event event)
  {
  t_int mouse;

  if (event.type == SDL_MOUSEBUTTONDOWN)
  {
  SDL_GetMouseState(&mouse.x, &mouse.y);
  SDL_SetRenderDrawColor(e->win.renderer, 255, 0, 0, 255);
  SDL_RenderDrawPoint(e->win.renderer, mouse.x, mouse.y);
  }
}*/

void			key_events(t_env *e)
{
	SDL_Event	event;

	copy_keyboard_state(e->win.keyb_curr, e->win.keyb_prev);
	e->win.keyb_curr = (Uint8 *)SDL_GetKeyboardState(NULL);
	player_events(e);
	mouse_events(e);
	while (SDL_PollEvent(&event))
	{
		//		menu_mvt(e, event);
		//		draw_map(e, event);
		exit_input(e, event);
	}
}
