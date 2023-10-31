/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:28:08 by ccraciun          #+#    #+#             */
/*   Updated: 2023/10/31 13:29:55 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
// int ft_putaddress_big(long unsigned int n);
static int apply_format (const char *format, va_list args, int i)
{
	int res;
	res = 0;
	if (format[i] == 'c')
		res += ft_putchar((char)va_arg(args, int));
	else if (format[i] == 'd')
		res += ft_putnbr(va_arg(args, int));
	else if (format[i] == 's')
		res += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'p')
		res += ft_putaddress(va_arg(args, long unsigned int));
	else if (format[i] == 'i')
		res += ft_putnbr(va_arg(args, int));
	else if (format[i] == 'u')
		res += ft_put_unsigned_nbr(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		res += ft_put_hex(va_arg(args, unsigned int));
	else if (format[i] == 'X')
		res += ft_put_hex(va_arg(args, unsigned int));
	else if (format[i] == '%')
		res += ft_putchar('%');
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int res;
	va_list	args;

	i = 0;
	res = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			res += apply_format(format, args, i);
			i++;
		}
		if(format[i] == '%')
			continue;
		res += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (res);
}

// int	main(void)
// {
// 	char *p = "hello";
// 	int i = 042;
// 	printf("my print ret is %d\n",ft_printf("%s \n", p));
// 	printf("orig printf ret is %d\n",printf("%s \n", p));
// 	return (0);
// }