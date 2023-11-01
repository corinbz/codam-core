/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:23:22 by corin             #+#    #+#             */
/*   Updated: 2023/11/01 11:27:28 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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