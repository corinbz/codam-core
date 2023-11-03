/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:25:10 by corin             #+#    #+#             */
/*   Updated: 2023/11/03 12:19:48 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putaddress(long unsigned int nb)
{
	int	digits;

	digits = 0;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	else if (nb < 16)
	{
		ft_putstr("0x");
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb + 'a' - 10);
		digits = 3;
	}
	else
	{
		digits = ft_putaddress(nb / 16);
		if (nb % 16 < 10)
			ft_putchar(nb % 16 + '0');
		else
			ft_putchar(nb % 16 + 'a' - 10);
		digits++;
	}
	return (digits);
}

int	ft_putaddress_big(long unsigned int nb)
{
	int	digits;

	digits = 0;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	else if (nb < 16)
	{
		ft_putstr("0x");
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb + 'A' - 10);
		digits = 3;
	}
	else
	{
		digits = ft_putaddress_big(nb / 16);
		if (nb % 16 < 10)
			ft_putchar(nb % 16 + '0');
		else
			ft_putchar(nb % 16 + 'A' - 10);
		digits++;
	}
	return (digits);
}
