/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:14:47 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/08 16:29:50 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	if (!little[0])
		return ((char*)big);
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			k = i;
			while (big[k] == little[j] && big[k] && k < len)
			{
				k++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
