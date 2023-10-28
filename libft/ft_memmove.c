/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:15:16 by corin             #+#    #+#             */
/*   Updated: 2023/10/28 14:00:37 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*d;
// 	unsigned char	*s;

// 	d = dest;
// 	s = (unsigned char *)src;
// 	if (d == s)
// 		return (dest);
// 	if (d < s)
// 	{
// 		ft_memcpy(dest, src, n);
// 	}
// 	else if (d > s)
// 	{
// 		while (n--)
// 			d[n] = s[n];
// 	}
// 	return (dest);
// }

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (dst && src)
	{
		if (dst > src)
		{
			while (len--)
				((unsigned char *)dst)[len] = ((const unsigned char *)src)[len];
		}
		else
		{
			while (++i < len)
				((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		}
		return (dst);
	}
	return (NULL);
}
