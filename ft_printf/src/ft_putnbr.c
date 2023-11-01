/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:22:43 by corin             #+#    #+#             */
/*   Updated: 2023/11/01 11:27:34 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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