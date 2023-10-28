/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:00:01 by corin             #+#    #+#             */
/*   Updated: 2023/10/10 21:00:02 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	char_c;
	char	*char_s;
	int		i;

	i = 0;
	char_s = (char *)s;
	char_c = c;
	while (char_s[i] != char_c)
	{
		if (char_s[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)char_s + i);
}
