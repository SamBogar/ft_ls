/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:14:28 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/10 20:06:54 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function returns a string which is the result of appending str2 to str1,
** with the option to free either, neither, or both of the given strings
**
**	0 == free nothing
**	1 == free str1
**	2 == free str2
**	3 == free str1 and str2
*/

char		*ft_strjoini(char *str1, char *str2, int to_free)
{
	char	*res;

	res = ft_strjoin(str1, str2);
	if (to_free == 1 || to_free == 3)
		free(str1);
	if (to_free == 2 || to_free == 3)
		free(str2);
	return (res);
}
