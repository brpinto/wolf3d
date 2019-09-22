/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:17:20 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/11 10:23:04 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_list	*ft_get_correct_file(const int fd, t_list **file)
{
	t_list *tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (&(*tmp));
}

static int		ft_read_line(char **line, void **content, int ret)
{
	size_t	i;
	char	*swap;

	i = 0;
	if (ret < BUFF_SIZE && !ft_strlen((char*)*content))
		return (0);
	while (((char*)*content)[i] != '\n' && ((char*)*content)[i] != '\0')
		i++;
	*line = ft_strsub(*content, 0, i);
	if (i < ft_strlen(*content) - 1)
	{
		swap = ft_strdup((char*)(*content + i + 1));
		free(*content);
		*content = swap;
	}
	else
		ft_strclr(*content);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*current;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	size_t			i;

	i = 0;
	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	current = ft_get_correct_file(fd, &(file));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(current->content = ft_strjoin_free(current->content, buff, 1)))
			return (-1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ft_read_line(line, &current->content, ret));
}
