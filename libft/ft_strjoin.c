/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:00:05 by corin             #+#    #+#             */
/*   Updated: 2023/10/28 13:37:50 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index;
	char	*result;

	index = 0;
	result = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char))
			+ 1);
	if (result == NULL)
		return (NULL);
	while (*s1)
	{
		result[index] = *s1;
		index++;
		s1++;
	}
	while (*s2)
	{
		result[index] = *s2;
		index++;
		s2++;
	}
	result[index] = '\0';
	return (result);
}
