/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:29:52 by jusaint-          #+#    #+#             */
/*   Updated: 2020/12/03 13:46:07 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	while (dest[i] != '\0')
		i++;
	ret = 0;
	while (src[ret] != '\0')
		ret++;
	if (size <= i)
		ret = ret + size;
	else
		ret = ret + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (ret);
}
