/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:19:59 by jusaint-          #+#    #+#             */
/*   Updated: 2020/12/20 19:24:28 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	trimlen(char const *s1, char const *set)
{
	size_t	blen;
	size_t	elen;

	blen = 0;
	elen = ft_strlen(s1);
	while (s1[blen] && charset(s1[blen], set))
		blen++;
	while (elen > blen && charset(s1[elen - 1], set))
		elen--;
	return (elen - blen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	trim = (char *)malloc(sizeof(char) * ((trimlen(s1, set) + 1)));
	if (!trim)
		return (NULL);
	while (charset(s1[i], set) == 1)
		i++;
	while (j < trimlen(s1, set))
	{
		trim[j] = s1[i];
		j++;
		i++;
	}
	trim[j] = '\0';
	return (trim);
}
