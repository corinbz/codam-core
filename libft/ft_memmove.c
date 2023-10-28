/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:15:16 by corin             #+#    #+#             */
/*   Updated: 2023/10/28 14:02:52 by ccraciun         ###   ########.fr       */
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
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((dest == NULL && src == NULL))
		return (dest);
	if ((size_t)dest - (size_t)src < n)
	{
		i = n - 1;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

