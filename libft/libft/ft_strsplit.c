/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:05:24 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/17 01:16:58 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	substrlen(char const *s, int i, char c)
{
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	substrnum(char const *s, char c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			i = substrlen(s, i, c);
			res++;
		}
		if (s[i])
			i++;
	}
	return (res);
}

static void	poptmp(char const *s, int end_sub, int beg_sub, char *tmp)
{
	int		i;

	i = 0;
	while (beg_sub != end_sub)
	{
		tmp[i] = s[beg_sub];
		i++;
		beg_sub++;
	}
	tmp[i] = '\0';
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	j = 0;
	i = 0;
	if (!s || !c ||
			!(res = (char**)malloc(sizeof(char*) * (substrnum(s, c) + 1))))
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			k = substrlen(s, i, c);
			res[j] = (char*)malloc(sizeof(char) * (k - i));
			poptmp(s, k, i, res[j]);
			i = k;
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	res[j] = 0;
	return (res);
}
