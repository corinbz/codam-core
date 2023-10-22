/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:59:13 by corin             #+#    #+#             */
/*   Updated: 2023/10/22 14:03:16 by ccraciun         ###   ########.fr       */
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

char *ft_itoa(int n) 
{
    int sign = 1;
    int digits_count;
    char *result;

    digits_count = get_digits(n);
    result = (char *)malloc(sizeof(char) * (digits_count + 1));
    if (!result)
        return result;
	if (n < 0) 
	{
        sign = -1;
		if(n == INT_MIN)
			return ("-2147483648");
        n = -n;
    }
    result[digits_count + 1] = '\0';

    while (digits_count > 0) {
        result[digits_count] = (n % 10) + '0';
        n /= 10;
        digits_count--;
    }

    if (sign == -1) {
        result[0] = '-';
    }

    return result;
}

int main()
{
	printf("%s\n",ft_itoa(INT_MIN));
}
