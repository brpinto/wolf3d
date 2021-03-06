/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:07:23 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/06/17 17:45:39 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		display_error(char *reason)
{
	ft_putendl(reason);
	exit(EXIT_FAILURE);
	return (1);
}
