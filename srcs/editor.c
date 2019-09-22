/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:41:21 by brpinto           #+#    #+#             */
/*   Updated: 2019/09/10 12:25:33 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <fcntl.h>

void	run_editor(t_env *e)
{
	(void)e;
	int fd;
	fd = open("~/Desktop/test", O_CREAT);
	printf("%d\n", fd);
	write(fd, "salut\n", 6);
}
