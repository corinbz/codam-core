/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:57:10 by corin             #+#    #+#             */
/*   Updated: 2023/11/01 11:14:08 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


int		ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int     ft_put_unsigned_nbr(unsigned int nb);
int	    ft_put_hex(long unsigned int nb);
int     ft_put_hex_up(long unsigned int nb);
int	    ft_putstr(char *str);
int	    ft_putaddress(long unsigned int n);
int	    ft_putaddress_big(long unsigned int n);
int		ft_printf(const char *format, ...);

#endif