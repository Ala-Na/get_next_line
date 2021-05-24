/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:01:55 by elanna            #+#    #+#             */
/*   Updated: 2021/05/24 16:42:42 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*dest;
	int		i;

	i = 0;
	size = 0;
	while (s && s[size])
		size++;
	dest = malloc(sizeof(*dest) * (size + 1));
	if (!dest)
		return (0);
	while (s[i] != 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = -1;
	size = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[size])
		size++;
	while (s2 && s2[++i])
		size++;
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		str[i++] = *s1++;
	while (s2 && *s2)
		str[i++] = *s2++;
	str[size] = 0;
	return (str);
}

t_content	*ft_contnew(char *buffer, int fd)
{
	t_content	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->buffer = ft_strdup(buffer);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

void	ft_contadd_back(t_content **alst, t_content *new)
{
	t_content	*last;

	if (!new)
		return ;
	else if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = *alst;
	while (last->next)
		last = last->next;
	last->next = new;
}

char	*ft_strchr_for_gnl(char *s, int c, int replace)
{
	while (s && *s)
	{
		if (*s == (char)c)
		{
			if (replace == 1)
				*s = 0;
			return ((char *)s);
		}
		s++;
	}
	if (c == 0 && *s == 0)
		return ((char *)s);
	return (0);
}
