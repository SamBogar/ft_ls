/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_through_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:44:19 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/10 20:26:48 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			append_directory(char *argument,
									struct stat st,
									t_files **to_affect)
{
	*to_affect = append_file(argument, st, *to_affect);
	if ((*to_affect)->path[ft_strlen((*to_affect)->path) - 1] != '/')
		(*to_affect)->path = ft_strjoini((*to_affect)->path, "/", 1);
	(*to_affect)->next = 0;
}

void			is_a_dir(t_env *env, struct stat st,
						char *argument, t_files **tmp_dir)
{
	if (!env->dirs)
	{
		append_directory(argument, st, &(env->dirs));
		get_dir_info(env->dirs, env->flags, env->dirs->path);
		*tmp_dir = env->dirs;
	}
	else
	{
		append_directory(argument, st, &(env->dirs->next));
		env->dirs = env->dirs->next;
		get_dir_info(env->dirs, env->flags, env->dirs->path);
		env->dirs->next = 0;
	}
}

void			is_a_file(t_env *env, struct stat st,
							char *argument, t_files **tmp_files)
{
	if (!env->files)
	{
		env->files = append_file(argument, st, env->files);
		*tmp_files = env->files;
	}
	else
	{
		env->files->next = append_file(argument, st,
										env->files->next);
		env->files = env->files->next;
	}
}

void			loop_through_args(t_env *env, int arg_num,
										int ac, char **av)
{
	struct stat		st;
	t_files			*tmp_files;
	t_files			*tmp_dir;

	tmp_files = 0;
	tmp_dir = 0;
	env->args = av + arg_num + 1;
	while (++arg_num < ac)
		if (lstat(av[arg_num], &st) >= 0)
		{
			if (S_ISREG(st.st_mode) > 0)
				is_a_file(env, st, av[arg_num], &tmp_files);
			else if (S_ISDIR(st.st_mode) > 0 || S_ISLNK(st.st_mode) > 0)
				is_a_dir(env, st, av[arg_num], &tmp_dir);
		}
		else
			ft_printf("ft_ls: %s: No such file or directory\n", av[arg_num]);
	env->dirs = tmp_dir;
	env->files = tmp_files;
}
