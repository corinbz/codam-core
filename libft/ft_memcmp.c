/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:59:29 by corin             #+#    #+#             */
/*   Updated: 2023/10/11 19:51:26 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = ptr1;
	p2 = ptr2;
	while (num-- > 0)
	{
		if (*p1 < *p2)
			return (-1);
		else if (*p1 > *p2)
			return (1);
		p1++;
		p2++;
	}
	return (0);
}
