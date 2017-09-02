/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:06:49 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/27 16:16:11 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			print_one(t_files *dir, unsigned int flags, int field_widths[5])
{
	char		permissions[11];

	if (flags & LOW_L)
	{
		populate_permissions(permissions, dir);
		long_format(dir, field_widths, permissions);
	}
	else
		ft_putendl(dir->name);
}

void			print_directory_contents(t_files *dir, unsigned int flags,
										char **args, int field_widths[5])
{
	bool		new_line;
	t_files		*tmp_contained;
	static int	print_multiple = 0;

	if (!print_multiple && are_multiple_dirs(dir, args, flags))
		print_multiple = 1;
	tmp_contained = dir->contained;
	new_line = print_preceding_info(print_multiple, flags, dir, args);
	while (dir->files)
	{
		print_selves(dir, &tmp_contained, flags, field_widths);
		if (!is_hidden(dir->files) || (flags & LOW_A))
			print_one(dir->files, flags, field_widths);
		dir->files = dir->files->next;
	}
	while (tmp_contained)
	{
		if ((is_not_self(tmp_contained) || (flags & LOW_A)) &&
			(!is_hidden(tmp_contained) || (flags & LOW_A)))
			print_one(tmp_contained, flags, field_widths);
		tmp_contained = tmp_contained->next;
	}
	if (new_line)
		write(1, "\n", 1);
}

void			print_files(t_files *dir, unsigned int flags, char **args)
{
	t_files		*tmp_files;
	int			field_widths[5];

	tmp_files = dir->files;
	instantiate_widths(field_widths);
	if (flags & LOW_L)
	{
		get_field_widths(dir->contained, field_widths);
		get_field_widths(dir->files, field_widths);
	}
	if ((!is_hidden(dir) || (flags & LOW_A)) || was_specified(dir, args))
		print_directory_contents(dir, flags, args, field_widths);
	free_files_list(tmp_files, true);
	if (dir->contained && (!is_hidden(dir) || (flags & LOW_A)))
		print_files(dir->contained, flags, args);
	if (dir->next)
		print_files(dir->next, flags, args);
	free_files_list(dir->contained, true);
}

t_files			*recursively_sort_list(t_files *head, unsigned int flags)
{
	t_files		*tmp;
	t_files		*tmp_head;

	tmp = sort_list(head, flags);
	tmp_head = tmp;
	while (tmp)
	{
		if (tmp->files)
			tmp->files = sort_list(tmp->files, flags);
		if (tmp->contained)
			tmp->contained = recursively_sort_list(tmp->contained, flags);
		tmp = tmp->next;
	}
	return (tmp_head);
}

void			print_out_list(t_env *env)
{
	int			field_widths[5];
	t_files		*tmp;

	instantiate_widths(field_widths);
	if (env->files)
	{
		get_field_widths(env->files, field_widths);
		env->files = recursively_sort_list(env->files, env->flags);
		tmp = env->files;
		while (env->files)
		{
			print_one(env->files, env->flags, field_widths);
			env->files = env->files->next;
		}
		write(1, "\n", 1);
		free_files_list(tmp, true);
	}
	if (env->dirs)
	{
		env->dirs = recursively_sort_list(env->dirs, env->flags);
		print_files(env->dirs, env->flags, env->args);
		free_files_list(env->dirs, true);
	}
	ft_memdel((void**)&env);
}
