/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:58:48 by ccraciun          #+#    #+#             */
/*   Updated: 2023/10/28 14:58:49 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int getArgumentCountTillZero(int first, ...)
{
  int count = 0;/*from  w  w w  . j a va  2  s.  co m*/
  int val = first;
  va_list vl, vl_count;
  va_start(vl, first);

  /* count number of arguments: */
  va_copy(vl_count, vl);

  while (val != 0) {
    val = va_arg(vl_count, int);
    ++count;
  }
  va_end(vl);
  return count;
}

int main()
{
  printf("%d", getArgumentCountTillZero(10, 20, 30, 40, 50, 0));
  return 0;
}