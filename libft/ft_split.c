/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:14:59 by jusaint-          #+#    #+#             */
/*   Updated: 2021/02/05 10:19:40 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wd_count(char const *s, char c)
{
	size_t	i;
	size_t	flag;
	size_t	wd;

	i = 0;
	flag = 1;
	wd = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 1)
			wd++;
		flag = (s[i] == c);
		i++;
	}
	return (wd);
}

static char	**fill_tab(char const *s, char **tab, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (i < wd_count(s, c))
	{
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != '\0' && s[k] != c)
		{
			tab[i][j] = s[k];
			j++;
			k++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static size_t	len_line(char const *s, char c, size_t index)
{
	size_t	len;

	len = 0;
	while (s[index + len] != c && s[index + len] != '\0')
		len++;
	return (len);
}

static void	*free_tab(char **tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(*tab) * (wd_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < wd_count(s, c))
	{
		while (s[index] == c)
			index++;
		tab[i] = (char *)malloc(sizeof(char) * (len_line(s, c, index) + 1));
		if (!tab)
			return (free_tab(tab, i));
		index = len_line(s, c, index) + index;
		i++;
	}
	fill_tab(s, tab, c);
	return (tab);
}
