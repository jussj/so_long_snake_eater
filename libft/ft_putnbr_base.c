/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusaint- <jusaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:19:20 by jusaint-          #+#    #+#             */
/*   Updated: 2021/03/01 12:20:25 by jusaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base)
		return (0);
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] && (base[i] != base[j]))
			j++;
		if (base[i] == base[j])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(long nbr, char *base)
{
	unsigned long int	nb;

	if (valid_base(base) == 1)
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd(45, 0);
		nb = nbr * (-1);
	}
	nb = nbr;
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putchar_fd(base[nb % ft_strlen(base)], 0);
	}
	else
		ft_putchar_fd(base[nb], 0);
}
