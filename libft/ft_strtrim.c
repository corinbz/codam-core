/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:00:57 by corin             #+#    #+#             */
/*   Updated: 2023/10/28 14:22:19 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int	is_char_in_set(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	begin;
	size_t	end;
	size_t	trimmed_length;
	char	*result;
	size_t	i;

	i = 0;
	begin = 0;
	end = ft_strlen((char *)s1);
	while (s1[begin] != '\0' && is_char_in_set(s1[begin], set))
		begin++;
	while (end > begin && is_char_in_set(s1[end - 1], set))
		end--;
	trimmed_length = end - begin;
	result = (char *)malloc(trimmed_length + 1);
	if (result == NULL)
		return (NULL);
	while (i < trimmed_length)
	{
		result[i] = s1[begin + i];
		i++;
	}
	result[trimmed_length] = '\0';
	return (result);
}
