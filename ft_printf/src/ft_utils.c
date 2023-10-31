/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:56:54 by corin             #+#    #+#             */
/*   Updated: 2023/10/31 13:30:23 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	long int	lnb;
	int digits = 0;

	lnb = nb;
	if (nb <= INT_MAX || nb >= INT_MIN)
	{
		if (lnb < 0)
		{
			write(1, "-", sizeof(char));
			digits++;
			lnb = -lnb;
		}
		if (lnb >= 10)
		{
			digits += ft_putnbr(lnb / 10);
		}
		ft_putchar(lnb % 10 + '0');
		digits++;
	}
	return (digits);

}

int ft_put_unsigned_nbr(unsigned int nb)
{
	unsigned int	unb;
	int digits = 0;

	unb = nb;
	if (nb <= UINT_MAX)
	{
		if (unb >= 10)
		{
			digits += ft_putnbr(unb / 10);
		}
		ft_putchar(unb % 10 + '0');
		digits++;
	}
	return (digits);

}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return i;
}
int ft_putaddress_big(long unsigned int nb)
{
	int digits = 0;
	if (nb == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
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
		digits = ft_putaddress(nb / 16);
		if (nb % 16 < 10)
			ft_putchar(nb % 16 + '0');
		else
			ft_putchar(nb % 16 + 'A' - 10);
		digits++;
	}
	return digits;
}
int	ft_putaddress(long unsigned int nb)
{
	int digits = 0;
	if (nb == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
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
	return digits;
}

int	ft_put_hex(long unsigned int nb)
{
	int digits = 0;
	if (nb == 0)
	{
		ft_putstr("(nil)");
		return (5);
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


