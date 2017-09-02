/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 21:52:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/16 21:44:28 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	tmp = (char*)malloc(sizeof(char) * len);
	len--;
	while (str[i])
	{
		tmp[i] = str[len];
		len--;
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
