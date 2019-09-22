/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:49:46 by brpinto           #+#    #+#             */
/*   Updated: 2019/09/09 18:50:17 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>

void		player_mvt(int key, t_player *player, t_map map)
{
	float	rad_angle;
	t_float	move;

	rad_angle = convert_to_rad(player->cam.angle);
	if (key == SDLK_w)
	{
		move.x = player->cam.pos.x + player->w_speed * cos(rad_angle);
		move.y = player->cam.pos.y - player->w_speed * sin(rad_angle);
	}
	else if (key == SDLK_s)
	{
		move.x = player->cam.pos.x - player->w_speed * cos(rad_angle);
		move.y = player->cam.pos.y + player->w_speed * sin(rad_angle);
	}
	else if (key == SDLK_d)
	{
		move.x = player->cam.pos.x + player->w_speed * cos(rad_angle - (M_PI / 2));
		move.y = player->cam.pos.y - player->w_speed * sin(rad_angle - (M_PI / 2));
	}
	else
	{
		move.x = player->cam.pos.x + player->w_speed * cos(rad_angle + (M_PI / 2));
		move.y = player->cam.pos.y - player->w_speed * sin(rad_angle + (M_PI / 2));
	}
	if (!ray_collision(move.x, move.y, &map))
	{
		player->cam.pos.x = move.x;
		player->cam.pos.y = move.y;
	}
}

void		player_rot(int key, t_player *player, int curr_mouse)
{
	(void)key;
/*	if (key == SDLK_q)
		player->cam.angle += player->r_speed;
	if (key == SDLK_e)
		player->cam.angle -= player->r_speed;*/
	player->cam.angle = angle_period((player->cam.angle + curr_mouse));
}

void		disp_player(t_env *e)
{
	e->win.disp_rect.x = e->player.cam.pos.x - (CUBE_SIZE / 2);
	e->win.disp_rect.y = e->player.cam.pos.y - (CUBE_SIZE / 2);
	e->win.disp_rect.w = CUBE_SIZE;
	e->win.disp_rect.h = CUBE_SIZE;
	SDL_SetRenderDrawColor(e->win.renderer, 0, 255, 0, 255);
	SDL_RenderDrawRect(e->win.renderer, &(e->win.disp_rect));
	SDL_RenderFillRect(e->win.renderer, &(e->win.disp_rect));
	SDL_SetRenderDrawColor(e->win.renderer, 255, 255, 180, 255);
}
