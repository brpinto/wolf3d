/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <brpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:40:14 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/09/18 14:49:59 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <fcntl.h>
# include <math.h>
# include <SDL.h>
//# include <SDL_image.h>
//# include <SDL_ttf.h>
#include <stdio.h>

# define VIEW_DIST 350
# define CUBE_SIZE 100
# define ANGLE 66.0
# define FPS_TARGET 1000 / 60

typedef enum			e_map_parse
{
	EMPTY = 0,
	WALL = 1,
	A_DOOR = 2,
	K_DOOR = 3,
	KEY = 4,
	W_BOX = 5,
	M_BOX = 6,
	CAM_N = 7,
	CAM_E = 8,
	CAM_S = 9,
	CAM_O = 10,
	EXIT,
}						t_map_parse;

typedef enum			e_state_game
{
	MENU = 0,
	GAME,
	MAP,
	FAIL,
	WIN,
}						t_state_game;

typedef enum			e_state_menu
{
	PLAY = 0,
	GUIDE,
	SETTINGS,
	QUIT,
	OUT,
}						t_state_menu;

typedef enum			e_bool
{
	FALSE = 0,
	TRUE,
}						t_bool;

typedef enum			e_sign
{
	NEG = -1,
	ZERO,
	POS,
}						t_sign;

typedef struct			s_int
{
	int					x;
	int					y;
}						t_int;

typedef struct			s_float
{
	float				x;
	float				y;
}						t_float;

typedef struct			s_win
{
	int					w;
	int					h;
	SDL_Window			*window;
	SDL_Event			event;
	SDL_Renderer		*renderer;
	SDL_Rect			disp_rect;
	Uint8				*keyb_curr;
	Uint8				keyb_prev[283];
}						t_win;

typedef struct			s_map
{
	int					w;
	int					h;
	int					**map;
}						t_map;

typedef struct			s_fov
{
	float				angle;
	t_float				start;
	t_float				end;
	t_float				last;
	t_float				current;
}						t_fov;

typedef struct			s_cam
{
	t_float				pos;
	float				angle;
	float				curr_angle;
	t_int				vision;
	unsigned int		fps;
	unsigned int		show_fps;
	int					sensitivity;
}						t_cam;

typedef struct			s_inventory
{
	int					key;
	int					ammo;
}						t_inventory;

typedef struct			s_player
{
	char				*name;
	t_int				w_speed;
	int					r_speed;
	int					hp;
	int					stamina;
	t_inventory			inventory;
	t_cam				cam;
	t_fov				fov;
}						t_player;

typedef struct			s_tex
{
	SDL_Texture			*ground;
	SDL_Texture			*sky;
	SDL_Texture			*key;
}						t_tex;

typedef struct			s_disp_list
{
	int					id;
	float				distance;
	t_float				pos;
	struct s_disp_list	*next;
}						t_disp_list;

typedef	struct			s_menu
{
	SDL_Surface			*bg;
	SDL_Texture			*bg_texture;
	SDL_Surface			*cursor;
	SDL_Texture			*cursor_texture;
	SDL_Rect			dest_cursor;
	float				divider;
	int					choice;
	int					in;
	int					oldin;
}						t_menu;

typedef struct			s_env
{
	t_menu				menu;
	t_map				*map;
	t_player			player;
	t_win				win;
	t_tex				tex;
	t_disp_list			*disp_lst;
	char				*editor;
}						t_env;

int						display_error(char *reason);
t_map					*parse(char *av);
void					init_env(t_env *e);
void					init_player(t_env *e);
void					key_events(t_env *e);
void					player_mvt(int key, t_player *player, t_map map);
//void					player_stop(int key, t_player *player);
void					player_rot(int key, t_player *player);
float					angle_period(float angle);
void					bresenham(t_env *e, t_cam *cam, t_float next_pos, int i);
void					bresenham2(t_env *e, SDL_Renderer *renderer, t_int start, t_int end);
void					display_minimap(t_env *e);
int						ray_collision(int x, int y, t_map *map);
t_int					convert_to_map(int x, int y);
float					convert_to_rad(float angle);
void					raycast(t_env *e, t_win *win, t_cam *cam);
void					draw_fov(SDL_Renderer *renderer, t_float current);
void					draw_wall(t_env *e, t_cam *cam, t_float current, int i);
void					run_editor(t_env *e);

//useless
void					print_tab(int **tab, int w, int h);

//brounch
void					run(t_env *e);
void					init_win(t_env *env, int w, int h);
void					init_menu(t_env *env);
void					init_option(t_env *env);
void					init_env(t_env *e);
void					init_vision(int cam_dir, t_cam *cam);
void					menu(t_env *env);
void					option(t_env *env);
void					disp_player(t_env *env);

#endif
