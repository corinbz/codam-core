/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:59:25 by corin             #+#    #+#             */
/*   Updated: 2023/10/11 19:51:27 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t				index;
	const unsigned char	*p;

	index = 0;
	p = ptr;
	while (index < num)
	{
		if (p[index] == (unsigned char)value)
			return ((void *)(p + index));
		index++;
	}
	return (NULL);
}
