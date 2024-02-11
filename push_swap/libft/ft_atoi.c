/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:58:55 by corin             #+#    #+#             */
/*   Updated: 2024/02/10 14:14:37 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isspace(int c)
{
	if ((c == ' ' || c == '\t' || c == '\v'
			|| c == '\n' || c == '\f' || c == '\r'))
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		digits;

	result = 0;
	sign = 1;
	digits = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' && ft_isdigit(*(str + 1)))
	{
		sign = -1;
		str++;
	}
	else if (*str == '+' && ft_isdigit(*(str + 1)))
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) && digits++ < 11)
			result = result * 10 + (*str - '0');
		else
			return (__INT64_MAX__);
		str++;
	}
	return (result * sign);
}
