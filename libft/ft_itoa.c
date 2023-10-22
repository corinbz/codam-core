/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:59:13 by corin             #+#    #+#             */
/*   Updated: 2023/10/22 13:45:28 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdbool.h>

static int	get_digits(int n)
{
	int			result;

	result = !n;
	while(n)
	{
		n /= 10;
		result++;
	}
	return result;
}

char	*ft_itoa(int n)
{
	bool sign;
	int digits_count;
	char *result;

	sign = n < 0;
	digits_count = get_digits(n) + sign;
	result = (char *)malloc(sizeof(char) * (digits_count + 1));
	if(!result)
		return(result);
	result[digits_count] = '\0';
	if(sign)
		*result = '-';
		result[--digits_count] = -(n % 10) + '0';
		n = (n / 10);
	while( digits_count-- - sign)
	{
		result[digits_count] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}

// int main()
// {
// 	printf("%d\n",get_digits(-100));
// }
