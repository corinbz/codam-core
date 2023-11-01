/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:25:51 by corin             #+#    #+#             */
/*   Updated: 2023/11/01 11:27:24 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_hex(long unsigned int nb)
{
	int digits = 0;
	if (nb == 0)
	{
		ft_putstr("0");
		return (1);
	}
	else if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb + 'a' - 10);
		digits = 1;
	}
	else
	{
		digits = ft_put_hex(nb / 16);
		if (nb % 16 < 10)
			ft_putchar(nb % 16 + '0');
		else
			ft_putchar(nb % 16 + 'a' - 10);
		digits++;
	}
	return digits;
}


int	ft_put_hex_up(long unsigned int nb)
{
	int digits = 0;
	if (nb == 0)
	{
		ft_putstr("0");
		return (1);
	}
	else if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb + 'A' - 10);
		digits = 1;
	}
	else
	{
		digits = ft_put_hex_up(nb / 16);
		if (nb % 16 < 10)
			ft_putchar(nb % 16 + '0');
		else
			ft_putchar(nb % 16 + 'A' - 10);
		digits++;
	}
	return digits;
}