/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:07:52 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/06/26 15:11:00 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_list	*file_to_list(int fd, t_map *map, t_list **list)
{
	t_list	*new;
	int		ret;
	char	*line;

	if ((ret = get_next_line(fd, &line)) < 0)
		return (NULL);
	*list = ft_lstnew(line, ft_strlen(line) + 1);
	map->w = ft_countcwords(line, ' ');
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((int)(ft_countcwords(line, ' ')) != map->w)
		{
			//free_all();
			return(NULL);
		}
		new = ft_lstnew(line, ft_strlen(line) + 1);
		free(line);
		ft_lstadd_end(list, new);
	}
	return (*list);
}

int		**list_to_tab(t_map *map, t_list *list)
{
	t_list	*lst;
	char	**split;
	int		i;
	int		j;

	lst = list;
	j = 0;
	map->h = ft_lst_size(list);
	if ((map->map = ft_tab_new_int(map->w, map->h)) == NULL)
		return(NULL);
	while (j < map->h)
	{
		i = 0;
		if ((split = ft_strsplit(lst->content, ' ')) == NULL)
			return (NULL);
		while (i < map->w)
		{
			if ((map->map[j][i] = ft_atoi(split[i])) < 0)
				return (NULL);
			i++;
		}
		lst = lst->next;
		j++;
	}
	return (map->map);
}

t_map	*parse(char *av)
{
	t_map	*map;
	int		fd;
	t_list	*list;

	map = NULL;
	if ((map = ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (NULL);
	if ((list = file_to_list(fd, map, &list)) == NULL)
		return (NULL);
	if ((map->map = list_to_tab(map, list)) == NULL)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	return (map);
}
