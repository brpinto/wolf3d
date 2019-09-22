/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:49:46 by brpinto           #+#    #+#             */
/*   Updated: 2019/09/18 13:40:23 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdio.h>

void		player_mvt(int key, t_player *player, t_map map)
{
	float	rad_angle;

	rad_angle = convert_to_rad(player->cam.angle);
	if (key == SDL_SCANCODE_W)
	{
		player->w_speed.x = 5 * cos(rad_angle);
		player->w_speed.y = -5 * sin(rad_angle);
	}
	if (key == SDL_SCANCODE_S)
	{
		player->w_speed.x = -5 * cos(rad_angle);
		player->w_speed.y = 5 * sin(rad_angle);
	}
	if (key == SDL_SCANCODE_D)
	{
		player->w_speed.x = 5 * cos(rad_angle - (M_PI / 2));
		player->w_speed.y = -5 * sin(rad_angle - (M_PI / 2));
	}
	if (key == SDL_SCANCODE_A)
	{
		player->w_speed.x = 5 * cos(rad_angle + (M_PI / 2));
		player->w_speed.y = -5 * sin(rad_angle + (M_PI / 2));
	}
	if (!ray_collision(player->cam.pos.x + player->w_speed.x, player->cam.pos.y + player->w_speed.y, &map))
	{
		player->cam.pos.x += player->w_speed.x;
		player->cam.pos.y += player->w_speed.y;
	}
}

/*void	player_stop(int key, t_player *player)
{
	if (key == SDL_SCANCODE_W)
	{
		if (player->w_speed.x > 0 && player->w_speed.y < 0)
		{
			player->w_speed.x = 0;
			player->w_speed.y = 0;
		}
	}
	if (key == SDLK_s)
	{
		if (player->w_speed.x < 0 && player->w_speed.y > 0)
		{
			player->w_speed.x = 0;
			player->w_speed.y = 0;
		}
	}
	if (key == SDLK_d)
	{
		if (player->w_speed.x > 0 && player->w_speed.y < 0)
		{
			player->w_speed.x = 0;
			player->w_speed.y = 0;
		}
	}
	if (key == SDL_SCANCODE_A)
	{
		if (player->w_speed.x > 0 && player->w_speed.y < 0)
		{
			player->w_speed.x = 0;
			player->w_speed.y = 0;
		}
	}
}*/

void		player_rot(int key, t_player *player)
{
	if (key == SDL_SCANCODE_Q)
		player->cam.angle += player->r_speed;
	if (key == SDL_SCANCODE_E)
		player->cam.angle -= player->r_speed;
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
