/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:31:53 by jusaint-          #+#    #+#             */
/*   Updated: 2021/05/12 14:37:58 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_index(char *base, char c)
{
	int		index;

	index = 0;
	while (c != base[index])
		index++;
	return (index);
}

int	ft_atoi_base(char *str, char *base)
{
	int		res;
	int		neg;
	int		base_len;
	int		i;

	res = 0;
	neg = 1;
	base_len = ft_strlen(base);
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == ' ' || str[i] == '\f'))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			res = res * base_len + base_index(base, str[i]);
		else
			return (res * neg);
	}
	return (res * neg);
}
