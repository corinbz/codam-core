/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:56:54 by corin             #+#    #+#             */
/*   Updated: 2023/10/30 13:43:22 by corin            ###   ########.fr       */
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
			ft_putnbr(lnb / 10);
		}
		ft_putchar(lnb % 10 + '0');
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
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb + 'A' - 10);
		digits++;
	}
	else
	{
		ft_putaddress_big(nb / 16);
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
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb + 'a' - 10);
		digits++;
	}
	else
	{
		ft_putaddress(nb / 16);
		if (nb % 16 < 10)
			ft_putchar(nb % 16 + '0');
		else
			ft_putchar(nb % 16 + 'a' - 10);
		digits++;
	}
	return digits;
}


