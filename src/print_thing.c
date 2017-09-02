/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_thing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:17:49 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/27 16:18:15 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_block_size(t_files *dir, unsigned int flags, char **args)
{
	t_files	*tmp_dirs;
	t_files	*tmp_files;
	int		block_size;

	block_size = 0;
	tmp_dirs = dir->contained;
	tmp_files = dir->files;
	while (tmp_dirs)
	{
		if ((!is_hidden(tmp_dirs) || (flags & LOW_A)) ||
				was_specified(tmp_dirs, args))
			if (is_not_self(tmp_dirs) || (flags & LOW_A))
				block_size += tmp_dirs->stats.st_blocks;
		tmp_dirs = tmp_dirs->next;
	}
	while (tmp_files)
	{
		if ((!is_hidden(tmp_files) || (flags & LOW_A)) ||
				was_specified(tmp_files, args))
			if (is_not_self(tmp_files) || (flags & LOW_A))
				block_size += tmp_files->stats.st_blocks;
		tmp_files = tmp_files->next;
	}
	if (block_size)
		ft_printf("total %d\n", block_size);
}

void		print_dir(unsigned int flags, t_files *dir,
					bool *new_line, char **args)
{
	if ((flags & CAP_R && is_not_self(dir)) || was_specified(dir, args))
	{
		if ((dir->path)[ft_strlen(dir->path) - 1] == '/' &&
				ft_strcmp(dir->path, "/"))
			(dir->path)[ft_strlen(dir->path) - 1] = ':';
		ft_putstr(dir->path);
		if (!ft_strcmp("/", dir->path))
			write(1, ":", 1);
		write(1, "\n", 1);
		*new_line = true;
	}
	else
		*new_line = false;
}

bool		print_preceding_info(int print_multiple, unsigned int flags,
							t_files *dir, char **args)
{
	bool	new_line;

	new_line = false;
	if (print_multiple)
		print_dir(flags, dir, &new_line, args);
	if (!(dir->stats.st_mode & S_IRUSR))
		ft_printf("ft_ls: %s: Permission denied\n", dir->name);
	if (flags & LOW_L && (dir->files || dir->contained))
		print_block_size(dir, flags, args);
	return (new_line);
}

void		print_selves(t_files *dir, t_files **tmp,
							unsigned int flags, int field_widths[5])
{
	int		(*cmp)(t_files *f, t_files *s);

	cmp = (flags & LOW_T) ?
			by_time : alphabetical;
	while (*tmp &&
		((cmp(*tmp, dir->files) && !(flags & LOW_R)) ||
			(!cmp(*tmp, dir->files) && (flags & LOW_R))))
	{
		if ((is_not_self(*tmp) || (flags & LOW_A)) &&
				(!is_hidden(*tmp) || (flags & LOW_A)))
			print_one(*tmp, flags, field_widths);
		*tmp = (*tmp)->next;
	}
}
