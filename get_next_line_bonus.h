/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:01:23 by elanna            #+#    #+#             */
/*   Updated: 2021/04/05 15:30:18 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_content
{
	char				*buffer;
	int					fd;
	struct s_content	*next;
}				t_content;

char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
t_content		*ft_lstnew(char *buffer, int fd);
void			ft_lstadd_back(t_content **alst, t_content *new);
void			ft_delcont(int fd, t_content **content);
t_content		*ft_lstchr_fd(t_content **lst, int fd);
int				get_content_line(int fd, char **line, ssize_t rd,
					t_content **cont);
void			fill_content_struct(t_content **content, char *buffer, int fd);
int				get_next_line(int fd, char **line);

#endif
