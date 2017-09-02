/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:22:25 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/27 16:08:08 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		instantiate_widths(int field_widths[5])
{
	field_widths[HARD_LINKS] = 0;
	field_widths[USER] = 0;
	field_widths[GROUP] = 0;
	field_widths[SIZE] = 0;
	field_widths[FILE_NAMES] = 0;
}

char		*truncate_date_and_time(char *date_and_time)
{
	int		i;
	int		colons;

	colons = 0;
	i = -1;
	while (colons != 2)
	{
		i++;
		if (date_and_time[i] == ':')
			colons++;
	}
	date_and_time[i + 1] = 0;
	date_and_time[ft_strlen(date_and_time) - 1] = 0;
	return (date_and_time + 4);
}

char		*truncate_path(char *path)
{
	if (path[ft_strlen(path) - 1] == '/' && ft_strcmp(path, "/"))
		path[ft_strlen(path) - 1] = 0;
	return (path);
}

void		long_format(t_files *dir, int field_widths[5], char permissions[11])
{
	char	*format;
	char	*date_and_time;
	char	sym_link_path[200];
	ssize_t	bytes;
	char	*tmp;

	format = get_format_string(field_widths);
	date_and_time = truncate_date_and_time(ctime(&dir->stats.st_mtime));
	ft_printf(format, permissions, dir->stats.st_nlink,
				getpwuid(dir->stats.st_uid)->pw_name,
				getgrgid(dir->stats.st_gid)->gr_name,
				dir->stats.st_size, date_and_time,
				dir->name);
	ft_memdel((void**)&format);
	if (S_ISLNK(dir->stats.st_mode) > 0)
	{
		tmp = ft_strdup(dir->path);
		tmp[ft_strlen(tmp) - 1] == '/' ? (tmp[ft_strlen(tmp) - 1] = 0) : 0;
		bytes = readlink(tmp, sym_link_path, 199);
		sym_link_path[bytes] = 0;
		ft_printf(" -> %s", sym_link_path);
		ft_memdel((void**)&tmp);
	}
	write(1, "\n", 1);
}
