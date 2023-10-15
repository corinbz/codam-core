/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:00:29 by corin             #+#    #+#             */
/*   Updated: 2023/10/11 20:06:07 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>
#include <string.h>

/*
It calculates the length of the source string src using strlen(src) to determine
how many characters need to be copied.

It ensures that there is enough space in the dest buffer to hold the copied
string. If the size is smaller than the length of src, it copies as many
characters as specified by size - 1 to leave room for the null-terminator.

It then copies the characters from src to dest, stopping when it reaches size -
1 characters or the null-terminator of src, whichever comes first.

Finally, it adds a null-terminator to the end of dest to ensure that it is a
properly null-terminated string.

The strlcpy function returns the total length of the source string src that was
supposed to be copied. This return value can be used to check whether the
copying operation was truncated due to insufficient space in the dest buffer.

*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
