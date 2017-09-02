/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:12:10 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/27 15:52:09 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

bool		is_not_self(t_files *dir)
{
	return (ft_strcmp(dir->name, ".") && ft_strcmp(dir->name, ".."));
}

bool		is_hidden(t_files *dir)
{
	return ((dir->name[0]) == '.' && is_not_self(dir));
}

bool		was_specified(t_files *dir, char **args)
{
	int		i;
	int		comparison;

	i = 0;
	if (!args)
		return (false);
	while (args[i])
		i++;
	if (i <= 1)
		return (false);
	i = -1;
	while (args[++i])
	{
		comparison = ft_strcmp(args[i], dir->path);
		if (!comparison ||
		(comparison == -47 && ft_strlen(args[i]) == ft_strlen(dir->path) - 1))
			return (true);
	}
	return (false);
}

bool		are_multiple_dirs(t_files *dir, char **args, unsigned int flags)
{
	int		i;
	t_files	*tmp;

	i = 0;
	tmp = dir->contained;
	if ((flags & CAP_R))
		while (tmp)
		{
			i++;
			if (S_ISLNK(tmp->stats.st_mode) > 0)
				i--;
			tmp = tmp->next;
		}
	if (i > 2)
		return (true);
	i = 0;
	if (!args)
		return (false);
	while (args[i] && args[i][0] == '-')
		i++;
	return ((args[i] && args[i + 1]) ? true : false);
}
