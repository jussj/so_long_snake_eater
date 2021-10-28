/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:27:56 by jusaint-          #+#    #+#             */
/*   Updated: 2020/12/15 23:11:24 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*map;

	i = 0;
	if (!s || !f)
		return (NULL);
	map = ft_strdup(s);
	if (!map)
		return (NULL);
	while (map[i])
	{
		map[i] = (*f)(i, map[i]);
		i++;
	}
	return (map);
}
