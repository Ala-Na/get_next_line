/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:01:40 by elanna            #+#    #+#             */
/*   Updated: 2021/04/06 11:45:51 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		ft_delcont(int fd, t_content **content)
{
	t_content	*fd_content;
	t_content	*prev_content;

	prev_content = *content;
	if (prev_content->fd == fd && !prev_content->next)
	{
		free(prev_content);
		*content = NULL;
		return ;
	}
	else if (prev_content->fd == fd && prev_content->next)
	{
		*content = prev_content->next;
		free(prev_content);
		return ;
	}
	while (prev_content->next != NULL && (prev_content->next)->fd != fd)
	{
		prev_content = prev_content->next;
	}
	fd_content = prev_content->next;
	prev_content->next = fd_content->next;
	free(fd_content);
	return ;
}

t_content	*ft_lstchr_fd(t_content **lst, int fd)
{
	t_content	*list;

	list = *lst;
	while (list)
	{
		if (fd == list->fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int			get_content_line(int fd, char **line, ssize_t rd, t_content **cont)
{
	t_content	*fd_content;
	char		*ptr;
	char		*tmp;

	if (*cont && !(fd_content = ft_lstchr_fd(cont, fd)))
		return (-1);
	if (rd == 0 && (!*cont || !(fd_content->buffer)))
	{
		*line = ft_strdup("");
		return (0);
	}
	ptr = ft_strchr(fd_content->buffer, '\n');
	if (ptr != NULL)
	{
		*ptr = '\0';
		*line = ft_strdup(fd_content->buffer);
		tmp = ft_strdup(++ptr);
		free(fd_content->buffer);
		fd_content->buffer = tmp;
		return (1);
	}
	*line = fd_content->buffer;
	fd_content->buffer = NULL;
	ft_delcont(fd, cont);
	return (0);
}

void		fill_content_struct(t_content **content, char *buffer, int fd)
{
	char		*tmp_buffer;
	t_content	*fd_content;

	if (!*content)
		*content = ft_lstnew(buffer, fd);
	else
	{
		fd_content = ft_lstchr_fd(content, fd);
		if (fd_content != NULL)
		{
			tmp_buffer = ft_strjoin(fd_content->buffer, buffer);
			free(fd_content->buffer);
			fd_content->buffer = tmp_buffer;
		}
		else
			ft_lstadd_back(content, ft_lstnew(buffer, fd));
	}
}

int			get_next_line(int fd, char **line)
{
	static t_content	*content;
	char				buffer[BUFFER_SIZE + 1];
	t_content			*fd_content;
	ssize_t				size_read;
	char				*new_line;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((size_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[size_read] = '\0';
		fill_content_struct(&content, buffer, fd);
		fd_content = ft_lstchr_fd(&content, fd);
		if (!fd_content)
			return (-1);
		new_line = ft_strchr(fd_content->buffer, '\n');
		if (new_line != NULL)
			break ;
	}
	if (size_read < 0)
		return (-1);
	return (get_content_line(fd, line, size_read, &content));
}
