/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:02:36 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/14 21:34:18 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_addnull(char *res, int j)
{
	res[j] = 0;
	return (res);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*res;
	size_t	len;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (len == (unsigned long)i)
	{
		res = (char*)malloc(1);
		res[0] = 0;
		return (res);
	}
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	if (!(res = (char*)malloc(sizeof(char) * (len - i + 1))))
		return (0);
	while (i < (int)len)
		res[j++] = s[i++];
	return (ft_addnull(res, j));
}
