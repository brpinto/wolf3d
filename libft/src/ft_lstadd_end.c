/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:11:05 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/11 13:00:58 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *current;

	current = *alst;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}
