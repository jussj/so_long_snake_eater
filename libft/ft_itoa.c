/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:05:23 by jusaint-          #+#    #+#             */
/*   Updated: 2020/12/20 19:22:50 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	nblen(long long int n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len = 2;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	int				neg;
	int				len;
	long long int	lln;

	lln = n;
	len = nblen(lln) - 1;
	neg = 0;
	nbr = (char *)malloc(sizeof(char) * len + 2);
	if (!nbr)
		return (0);
	nbr[len + 1] = '\0';
	if (lln < 0)
	{
		nbr[0] = '-';
		lln = lln * -1;
		neg = 1;
	}
	while (len >= neg)
	{
		nbr[len] = lln % 10 + '0';
		lln = lln / 10;
		len--;
	}
	return (nbr);
}
