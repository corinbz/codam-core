/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handeling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:47 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/24 11:27:48 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool ac_check(int ac, char **av)
{
	if (ac != 5)
		return(perror("you must have exactly 4 arguments"), false);
	return (true);
}