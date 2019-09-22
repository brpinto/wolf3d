/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:29:40 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/09/09 13:44:12 by qbenaroc         ###   ########.fr       */
/*   Updated: 2019/08/20 19:42:47 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	init_vision(int cam_dir, t_cam *cam)
{
	if (cam_dir == CAM_N)
	{
		cam->vision.x = 0;
		cam->vision.y = -1;
		cam->angle = 90;
	}
	else if (cam_dir == CAM_E)
	{
		cam->vision.x = 1;
		cam->vision.y = 0;
		cam->angle = 0;
	}
	else if (cam_dir == CAM_S)
	{
		cam->vision.x = 0;
		cam->vision.y = 1;
		cam->angle = 270;
	}
	else
	{
		cam->vision.x = -1;
		cam->vision.y = 0;
		cam->angle = 180;
	}
}

void	init_player_pos(t_env *e)
{
	int		i;
	int		j;

	j = 0;
	while (j < e->map->h)
	{
		i = 0;
		while (i < e->map->w)
		{
			if (e->map->map[j][i] == CAM_N || e->map->map[j][i] == CAM_E
				|| e->map->map[j][i] == CAM_S || e->map->map[j][i] == CAM_O)
			{
				init_vision(e->map->map[j][i], &e->player.cam);
				e->player.cam.pos.x = (i * CUBE_SIZE) + (CUBE_SIZE / 2);
				e->player.cam.pos.y = (j * CUBE_SIZE) + (CUBE_SIZE / 2);
				return ;
			}
			i++;
		}
		j++;
	}
}

void		init_player(t_env *e)
{
	e->player.w_speed = 5;
	e->player.r_speed = 5;
	e->player.hp = 100;
	init_player_pos(e);
}

void		init_win(t_env *e, int w, int h)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	e->win.w = w;
	e->win.h = h;
	e->win.window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, e->win.w, e->win.h, SDL_WINDOW_RESIZABLE);
	SDL_PumpEvents();
	e->win.current_state = (Uint8 *)SDL_GetKeyboardState(NULL);
	e->win.renderer = SDL_CreateRenderer(e->win.window, -1, SDL_RENDERER_ACCELERATED);
	e->menu.in = MENU;
	e->menu.oldin = e->menu.in;
}

void		init_option(t_env *e)
{
	SDL_DestroyTexture(e->menu.bg_texture);
	SDL_DestroyTexture(e->menu.cursor_texture);
	e->menu.bg = SDL_LoadBMP("./images/option.bmp");
	e->menu.bg_texture = SDL_CreateTextureFromSurface(e->win.renderer, e->menu.bg);
	SDL_RenderCopy(e->win.renderer, e->menu.bg_texture, NULL, NULL);
}

void		init_menu(t_env *e)
{
/*	if (key_pressed(&(e->win), SDL_SCANCODE_RETURN) && e->menu.choice == QUIT)
	{
		SDL_Quit();
		exit(0);
	}
*/
	SDL_DestroyTexture(e->menu.bg_texture);
	SDL_DestroyTexture(e->menu.cursor_texture);
	e->menu.bg = SDL_LoadBMP("./images/menu.bmp");
	e->menu.bg_texture = SDL_CreateTextureFromSurface(e->win.renderer, e->menu.bg);
	e->menu.cursor = SDL_LoadBMP("./images/cursor_pourri.bmp");
	e->menu.cursor_texture = SDL_CreateTextureFromSurface(e->win.renderer, e->menu.cursor);
	SDL_RenderCopy(e->win.renderer, e->menu.bg_texture, NULL, NULL);
	SDL_RenderCopy(e->win.renderer, e->menu.cursor_texture, NULL, &(e->menu.dest_cursor));
}

void			init_env(t_env *e)
{
	ft_bzero(e, sizeof(t_env));
}
