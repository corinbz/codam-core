/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:28:08 by ccraciun          #+#    #+#             */
/*   Updated: 2023/11/03 12:12:29 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	apply_format(char format, va_list args)
{
	int	res;

	res = 0;
	if (format == 'c')
		res = ft_putchar((char)va_arg(args, int));
	if (format == 'd')
		res = ft_putnbr(va_arg(args, int));
	if (format == 's')
		res = ft_putstr(va_arg(args, char *));
	if (format == 'p')
		res = ft_putaddress(va_arg(args, long unsigned int));
	if (format == 'i')
		res = ft_putnbr(va_arg(args, int));
	if (format == 'u')
		res = ft_put_unsigned_nbr(va_arg(args, unsigned int));
	if (format == 'x')
		res = ft_put_hex(va_arg(args, unsigned int));
	if (format == 'X')
		res = ft_put_hex_up(va_arg(args, unsigned int));
	if (format == '%')
		res = ft_putchar('%');
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	res = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			res += apply_format((char)format[i], args);
			i++;
			continue ;
		}
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