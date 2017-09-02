/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:29:21 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/09 16:32:38 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				alphabetical(t_files *first, t_files *second)
{
	if (!ft_strcmp(first->name, ".") && !ft_strcmp(second->name, ".."))
		return (1);
	else if (!ft_strcmp(second->name, ".") && !ft_strcmp(first->name, ".."))
		return (0);
	if (ft_strcmp(first->path, second->path) < 0)
		return (1);
	return (0);
}

int				by_time(t_files *first, t_files *second)
{
	if (first->stats.st_mtime > second->stats.st_mtime)
		return (1);
	else if (first->stats.st_mtime == second->stats.st_mtime)
	{
		if (first->stats.st_mtimespec.tv_nsec >
			second->stats.st_mtimespec.tv_nsec)
			return (1);
	}
	return (0);
}
