/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:58:55 by corin             #+#    #+#             */
/*   Updated: 2023/10/28 13:54:59 by ccraciun         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	index;

	result = 0;
	sign = 1;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	return (result * sign);
}
