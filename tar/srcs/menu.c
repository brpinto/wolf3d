/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:14:35 by brpinto           #+#    #+#             */
/*   Updated: 2019/07/29 16:48:46 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	menu(t_env *e)
{
/*
	init_menu(e);
	if (key_pressed(&(e->win), SDL_SCANCODE_DOWN))
	{
		if (e->menu.choice < QUIT)
			e->menu.choice++;
		else
			e->menu.choice = 0;
	}
	if (key_pressed(&(e->win), SDL_SCANCODE_UP))
	{
		if (e->menu.choice > 0)
			e->menu.choice--;
		else
			e->menu.choice = QUIT;
	}
	e->menu.dest_cursor.y = 220 + 115 * e->menu.choice;
	if (key_pressed(&(e->win), SDL_SCANCODE_RETURN))
	{
		(e->menu.choice == PLAY && e->menu.in == MENU) ? game(e) : 0;
		(e->menu.choice == SETTINGS && e->menu.in == MENU) ? option(e) : 0;
	}
	//	e->menu.divider = 3;
	e->menu.dest_cursor.x = e->win.w / 3;
	e->menu.dest_cursor.w = e->menu.cursor->w / 2;
	e->menu.dest_cursor.h = e->menu.cursor->h / 2;
*/
	(void)e;
}

void option(t_env *e)
{
/*	int size;

	size = 0;
	e->menu.choice = 0;
	init_option(e);
	if (key_pressed(&(e->win), SDL_SCANCODE_ESCAPE)
			&& (e->menu.in != e->menu.oldin))
		e->menu.oldin == MENU ? e->menu.choice = 0 : 0;
	if (e->menu.choice == 0 && size == 0)
	{
		if (key_pressed(&(e->win), SDL_SCANCODE_RIGHT) || (key_pressed(&(e->win), SDL_SCANCODE_LEFT)))
		{
			ft_putendl("screen size");
			size++;
		}
		if (key_pressed(&(e->win), SDL_SCANCODE_RETURN) && size != 0)
		{
			SDL_DestroyWindow(e->win.window);
		}
	}
*/
	(void)e;
}
