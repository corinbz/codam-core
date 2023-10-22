/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:59:13 by corin             #+#    #+#             */
/*   Updated: 2023/10/22 15:26:10 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdbool.h>

// static int	get_digits(int n)
// {
// 	int			result;
	
// 	if (n == 0)
// 		return (1);
// 	result = !n;
// 	while(n)
// 	{
// 		n /= 10;
// 		result++;
// 	}
// 	return result;
// }

static int	get_digits(int n)
{
	int			result;
	long int	long_n;

	long_n = n;
	result = 0;
	if (long_n < 0)
	{
		result++;
		long_n *= -1;
	}
	while (long_n > 0)
	{
		long_n /= 10;
		result += 1;
	}
	return (result);
}

char	*get_reversed(int n)
{
	char		c[100];
	size_t		i;
	long int	long_n;

	long_n = n;
	i = 0;
	if (long_n < 0)
	{
		long_n *= -1;
	}
	while (long_n > 0)
	{
		c[i] = long_n % 10 + '0';
		long_n /= 10;
		i++;
	}
	c[i] = '\0';
	return (c);
}

static char	*ft_itoa_zero(void)
{
	char	*result;

	result = (char *)malloc(2);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*reversed;
	size_t	index;
	char	*result;

	digits = get_digits(n);
	reversed = get_reversed(n);
	index = 0;
	if (n == 0)
	{
		result = ft_itoa_zero();
		return (result);
	}
	result = (char *)malloc(((digits + 1) * sizeof(char)));
	if (result == NULL)
		return (NULL);
	result[digits] = '\0';
	while (--digits >= 0)
		result[digits] = reversed[index++];
	if (n < 0)
		result[0] = '-';
	return (result);
}

// int main()
// {
// 	printf("%s\n",ft_itoa(INT_MIN));
// }
