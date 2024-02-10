/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:43:13 by ccraciun          #+#    #+#             */
/*   Updated: 2023/10/28 13:36:37 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_put_int(long int a, int fd)
{
	char	c;

	c = a % 10 + '0';
	write(fd, &c, sizeof(char));
}

void	ft_putnbr_fd(int nb, int fd)
{
	long int	lnb;

	lnb = nb;
	if (nb <= INT_MAX || nb >= INT_MIN)
	{
		if (lnb < 0)
		{
			write(fd, "-", sizeof(char));
			lnb = -lnb;
		}
		if (lnb >= 10)
		{
			ft_putnbr_fd(lnb / 10, fd);
		}
		ft_put_int(lnb, fd);
	}
}
