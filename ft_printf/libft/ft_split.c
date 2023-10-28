/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:59:43 by corin             #+#    #+#             */
/*   Updated: 2023/10/22 15:35:39 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
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
	else
		ft_strlcpy(substr, s, len + 1);
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
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !(result))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			result[index] = create_substring(s, c);
			if (result[index] == NULL)
				check_alloc_fail(result, index);
			s += substr_len(s, c);
			index++;
		}
	}
	result[index] = NULL;
	return (result);
}

// int main()
// {
// 	char **result = ft_split("hello", ' ');
// 	int i = 0;

// 	while(result[i] != NULL)
// 	{
// 		printf("index %d is %s\n",i,result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result[i]);
// 	free(result);
// }
