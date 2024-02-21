/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handeling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:47 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/21 18:21:57 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

bool ac_check(int ac, char **av)
{
	if (ac != 5)
		return(perror("you must have exactly 4 arguments"), false);
	return (true);
}