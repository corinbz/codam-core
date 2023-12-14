/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:39:22 by corin             #+#    #+#             */
/*   Updated: 2023/12/12 15:08:27 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// calloc
void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void			*result;
	unsigned char	*p;

	result = malloc(num_elements * element_size);
	if (!result)
		return (NULL);
	p = (unsigned char *)result;
	while (num_elements != 0)
	{
		*p = '\0';
		p++;
		num_elements--;
	}
	return (result);
}

// duplicate the string
char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str)
		return (ft_strdup(""));
	while (str[i])
		i++;
	new_str = ft_calloc(i + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

// join the strings
char	*join_strs(const char *s1, const char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	result = ft_calloc(i + j + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++j])
		result[i + j] = s2[j];
	return (result);
}

// check if text contains newline
int	contains_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// free the strings
void	ft_free_all(char **str1, char **str2, char **str3)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}
