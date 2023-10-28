/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:00:51 by corin             #+#    #+#             */
/*   Updated: 2023/10/14 16:10:26 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;

	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (len > 0 && *haystack)
	{
		index = 0;
		while ((haystack[index] == needle[index])
			&& haystack[index] && len - index > 0)
		{
			index++;
		}
		if (needle[index] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
