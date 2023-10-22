/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:59:13 by corin             #+#    #+#             */
/*   Updated: 2023/10/22 14:29:12 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdbool.h>

static int	get_digits(int n)
{
	int			result;
	
	if (n == 0)
		return (1);
	result = !n;
	while(n)
	{
		n /= 10;
		result++;
	}
	return result;
}
// void reverse(char str[], int len)
// {
//     int start, end;
//     char temp;
// 	start = 0;
// 	end = len -1;
//     while(start < end) {
//         temp = *(str+start);
//         *(str+start) = *(str+end);
//         *(str+end) = temp;
// 		start++;
// 		end--;
//     }
// }

char *ft_itoa(int n) 
{
    int sign = 1;
    int digits_count;
    char *result;
	int index;

    digits_count = get_digits(n);
    result = (char *)malloc(sizeof(char) * (digits_count + 1));
    if (result == NULL)
		return NULL;
	if (n < 0) 
	{
        sign = -1;
		if(n == INT_MIN)
			return ("-2147483648");
        n = -n;
    }
    result[digits_count + 1] = '\0';
	index = digits_count - 1;
    while (n > 0) {
        result[index] = (n % 10) + '0';
        n /= 10;
        index--;
    }

    if (sign == -1) {
        result[0] = '-';
    }
	result[digits_count] = '\0';
    return result;
}

// int main()
// {
// 	printf("%s\n",ft_itoa(10));
// }
