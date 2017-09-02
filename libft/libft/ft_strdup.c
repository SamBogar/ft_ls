/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:37:01 by sbogar            #+#    #+#             */
/*   Updated: 2017/07/27 14:28:01 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(s1);
	res = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
