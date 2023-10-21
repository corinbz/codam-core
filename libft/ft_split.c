/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:59:43 by corin             #+#    #+#             */
/*   Updated: 2023/10/21 11:00:15 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		if (*s == c)
			result++;
		s++;
	}
	return (result);
}

static size_t	substr_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char	*create_substring(const char *s, char c)
{
	size_t	len;
	char	*substr;

	len = substr_len(s, c);
	if (len == 0)
		return (NULL);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	else if (substr)
	{
		ft_strlcpy(substr, s, len + 1);
	}
	return (substr);
}

char	*check_alloc_fail(char **result, int index)
{
	while (index >= 0)
	{
		free(result[index]);
		index--;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**result;

	index = 0;
	result = (char **)malloc(sizeof(*result) * (count_words(s, c) + 1));
	if (!s || !(result))
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			result[index] = create_substring(s, c);
			if (result[index] == NULL)
				check_alloc_fail(result, index);
			s += substr_len(s, c) + 1;
			index++;
		}
	}
	result[index] = NULL;
	return (result);
}
