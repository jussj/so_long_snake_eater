/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:14:42 by jusaint-          #+#    #+#             */
/*   Updated: 2020/12/03 14:50:31 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = NULL;
	while (s[i])
	{
		if ((char)c == s[i])
			ptr = ((char *)s + i);
		i++;
	}
	if (ptr != NULL)
		return (ptr);
	if ((char)c == s[i])
		return ((char *)s + i);
	return (NULL);
}
