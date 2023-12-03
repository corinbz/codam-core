/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:00:55 by corin             #+#    #+#             */
/*   Updated: 2023/10/28 13:38:50 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *str, int character)
{
	int		index;
	char	char_c;
	char	*char_s;

	char_c = character;
	char_s = (char *)str;
	index = ft_strlen((char *)str);
	while (index >= 0)
	{
		if (char_s[index] == char_c)
			return (char_s + index);
		index--;
	}
	return (NULL);
}
