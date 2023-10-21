/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:59:43 by corin             #+#    #+#             */
/*   Updated: 2023/10/21 13:54:35 by ccraciun         ###   ########.fr       */
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
		if (*s != c)
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

char	**check_alloc_fail(char **result, int index)
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
	result = (char **)malloc(sizeof(*result) * (count_words(s, c)));
	if (!s || !(result))
		return (NULL);
	while (*s)
	{
		// printf("%s\n", s);
		if (*s == c)
			s++;
		else
		{
			result[index] = create_substring(s, c);
			if (result[index] == NULL)
				return (check_alloc_fail(result, index));
			s += substr_len(s, c);
			index++;
		}
	}
	// printf("the index = %i", index);
	result[index] = NULL;
	return (result);
}

// int main()
// {
// 	char **result = ft_split("@@@test@sadsadsa", ' ');
// 	int i = 0;

// 	while(result[i] != NULL)
// 	{
// 		printf("index %d is %s\n",i,result[i]);
// 		i++;
// 	}
// }
