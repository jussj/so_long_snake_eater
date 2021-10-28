/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:00:18 by jusaint-          #+#    #+#             */
/*   Updated: 2021/04/10 11:00:23 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_str(char *str, char *buff)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;
	unsigned int	size;

	i = 0;
	j = 0;
	if (!buff)
		return (NULL);
	if (!str)
		return (ft_strdup(buff));
	size = ft_strlen(str) + ft_strlen(buff);
	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (ft_free_malloc(str));
	while (str[i])
		new[j++] = str[i++];
	i = 0;
	while (buff[i])
		new[j++] = buff[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

static char	*trim_str(char *str, int flag, int ret)
{
	int		i;
	int		j;
	int		size;
	char	*trim;

	if (!str)
		return (NULL);
	if (str && flag < 0 && ret == 0)
		return (ft_free_malloc(str));
	size = ft_strlen(str) - flag;
	trim = (char *)malloc(sizeof(char) * size);
	if (!trim)
		return (ft_free_malloc(str));
	i = flag + 1;
	j = 0;
	while (str[i])
		trim[j++] = str[i++];
	trim[j] = '\0';
	free(str);
	return (trim);
}

static int	end_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*return_line(char *str, int len, int ret, int flag)
{
	int		i;
	char	*next;

	i = 0;
	if (ret == 0 && flag < 0)
		len = ft_strlen(str);
	next = (char *)malloc(sizeof(char) * (len + 1));
	if (!next)
		return (NULL);
	if (!str)
	{
		*next = 0;
		return (next);
	}
	while (i < len)
	{
		next[i] = str[i];
		i++;
	}
	next[i] = '\0';
	return (next);
}

int	get_next_line(int fd, char **line)
{
	static char		*str[FD_MAX];
	char			buffer[BUFFER_SIZE + 1];
	int				ret;

	ret = 0;
	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		str[fd] = join_str(str[fd], buffer);
		if (!str[fd])
			return (-1);
		if (end_line(str[fd]) >= 0)
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	*line = return_line(str[fd], end_line(str[fd]), ret, end_line(str[fd]));
	str[fd] = trim_str(str[fd], end_line(str[fd]), ret);
	if (!str[fd] && ret > 0)
		return (-1);
	if ((end_line(str[fd]) < 0) && !str[fd] && ret == 0)
		return (0);
	return (1);
}
