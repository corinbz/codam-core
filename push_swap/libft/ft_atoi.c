/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:58:55 by corin             #+#    #+#             */
/*   Updated: 2024/02/04 15:01:05 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

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
	int		index;

	result = 0;
	sign = 1;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' && ft_isdigit(str[index + 1]))
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+' && ft_isdigit(str[index + 1]))
		index++;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			result = result * 10 + str[index] - '0';
		else
			return (__INT64_MAX__);
		index++;
	}
	return (result * sign);
}
