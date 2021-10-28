/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:18:48 by jusaint-          #+#    #+#             */
/*   Updated: 2020/12/11 18:11:59 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && len > i)
	{
		if (little[0] == big[i])
		{
			j = 0;
			ptr = (char *)big + i;
			while (little[j] == big[i + j] && i + j < len)
			{
				if (little[j + 1] == '\0')
					return (ptr);
				j++;
			}
			ptr = 0;
		}
		i++;
	}
	return (NULL);
}
