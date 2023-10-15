/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:32:36 by ccraciun          #+#    #+#             */
/*   Updated: 2023/10/15 11:38:15 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	int		i;
	char	*result;
	char	*s;

	s = (char *)str;
	str_len = ft_strlen_const (str);
	i = 0;
	if (str_len == 0)
	{
		result = malloc (1);
		result[0] = '\0';
		return (result);
	}
	result = malloc ((str_len + 1) * sizeof (char));
	if (result == NULL)
		return (NULL);
	while (str[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
