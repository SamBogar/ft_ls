/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 17:05:08 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/10 19:58:17 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			recursive_get_dir(char *p_or_n[2],
										t_files *new_dir,
										unsigned int flags,
										struct stat st)
{
	t_files			*tmp;

	new_dir->contained = append_file(p_or_n[0], st,
									new_dir->contained);
	tmp = new_dir->contained;
	while (tmp->next)
		tmp = tmp->next;
	if ((flags & CAP_R) &&
			ft_strcmp(p_or_n[1], ".") &&
			ft_strcmp(p_or_n[1], ".."))
		get_dir_info(tmp, flags, p_or_n[0]);
}

void				get_dir_info(t_files *new_dir,
										unsigned int flags, char *path)
{
	DIR				*this_directory;
	struct dirent	*entries;
	struct stat		st;
	char			*p_or_n[2];

	this_directory = opendir(new_dir->path);
	if (!this_directory)
		return ;
	while ((entries = readdir(this_directory)) != NULL)
	{
		p_or_n[0] = ft_strjoin(path, entries->d_name);
		p_or_n[1] = entries->d_name;
		if (lstat(p_or_n[0], &st) >= 0)
		{
			if (S_ISREG(st.st_mode) > 0)
				new_dir->files = append_file(p_or_n[0], st, new_dir->files);
			else if (S_ISDIR(st.st_mode) > 0 || S_ISLNK(st.st_mode) > 0)
			{
				p_or_n[0] = ft_strjoini(p_or_n[0], "/", 1);
				recursive_get_dir(p_or_n, new_dir, flags, st);
			}
		}
		free(p_or_n[0]);
	}
	closedir(this_directory);
}

void				get_files(t_env *env, int last_flag_arg, int ac, char **av)
{
	bool			files_are_specified;
	struct stat		st;

	files_are_specified = (last_flag_arg != ac);
	if (files_are_specified)
		loop_through_args(env, last_flag_arg - 1, ac, av);
	else
	{
		env->files = 0;
		env->args = 0;
		stat(".", &st);
		append_directory(".", st, &(env->dirs));
		get_dir_info(env->dirs, env->flags, env->dirs->path);
		env->dirs->next = 0;
	}
}
