/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:12:43 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/08 23:41:15 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				j;
	char			*res;

	if (!s)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (int)len + 1);
	if (res == NULL)
		return (NULL);
	j = 0;
	i = start;
	while (i - start < (unsigned int)len)
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
