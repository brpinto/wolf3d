/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brounch <brounch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:35:48 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/08/05 16:36:15 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <wolf3d.h>

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		return (display_error("not enough arguments\nusage : ./wolf3d [map_file]"));
	init_env(&e);
	if ((e.map = parse(av[1])) == NULL)
		return (display_error("invalid map file"));
	init_win(&e, 1080, 720);
	init_player(&e);
	run(&e);
	return (0);
}
