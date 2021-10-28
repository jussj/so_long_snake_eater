/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:25:14 by jusaint-          #+#    #+#             */
/*   Updated: 2020/12/15 12:08:59 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*destmp;
	unsigned char	*srctmp;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	destmp = (unsigned char *)dest;
	srctmp = (unsigned char *)src;
	while (i < n)
	{
		destmp[i] = srctmp[i];
		i++;
	}
	return (destmp);
}
