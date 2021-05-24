/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:01:23 by elanna            #+#    #+#             */
/*   Updated: 2021/05/24 16:37:26 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_content
{
	char				*buffer;
	int					fd;
	struct s_content	*next;
}				t_content;

char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr_for_gnl(char *s, int c, int replace);
t_content		*ft_contnew(char *buffer, int fd);
void			ft_contadd_back(t_content **alst, t_content *new);
void			ft_delcont(int fd, t_content **content);
t_content		*ft_lstchr_fd(t_content **lst, int fd);
int				get_content_line(int fd, char **line, ssize_t rd,
					t_content **cont);
void			fill_content_struct(t_content **content, char *buffer, int fd);
int				get_next_line(int fd, char **line);

#endif
