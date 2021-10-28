/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:59:02 by jusaint-          #+#    #+#             */
/*   Updated: 2020/12/14 21:57:40 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*destmp;
	unsigned char	*srctmp;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	destmp = (unsigned char *)dest;
	srctmp = (unsigned char *)src;
	if (destmp < srctmp)
	{
		while (i++ < n)
			destmp[i - 1] = srctmp[i - 1];
	}
	else
	{
		while (i < n)
		{
			destmp[n - 1] = srctmp[n - 1];
			n--;
		}
	}
	return (dest);
}
