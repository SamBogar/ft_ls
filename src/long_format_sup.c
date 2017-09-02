/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format_sup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:22:25 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/27 15:22:36 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			get_field_widths(t_files *head, int fws[5])
{
	t_files		*t;

	t = head;
	while (t)
	{
		fws[0] = ft_digitcounter(t->stats.st_nlink) > fws[0] ?
									ft_digitcounter(t->stats.st_nlink) :
									fws[0];
		fws[1] = ft_strlen(getpwuid(t->stats.st_uid)->pw_name) >
								(size_t)fws[1] ?
								ft_strlen(getpwuid(t->stats.st_uid)->pw_name) :
								fws[1];
		fws[2] = ft_strlen(getgrgid(t->stats.st_gid)->gr_name) >
								(size_t)fws[2] ?
								ft_strlen(getgrgid(t->stats.st_gid)->gr_name) :
								fws[2];
		fws[3] = ft_digitcounter(t->stats.st_size) > fws[3] ?
								ft_digitcounter(t->stats.st_size) :
								fws[3];
		fws[4] = ft_strlen(t->name) > (size_t)fws[4] ?
									ft_strlen(t->name) :
									fws[4];
		t = t->next;
	}
}

char			get_file_mode(t_files *dir)
{
	char		res;

	res = (S_ISBLK(dir->stats.st_mode) ? 'b' : '-');
	res = (S_ISCHR(dir->stats.st_mode)) ? 'c' : res;
	res = (S_ISDIR(dir->stats.st_mode)) ? 'd' : res;
	res = (S_ISLNK(dir->stats.st_mode)) ? 'l' : res;
	res = (S_ISSOCK(dir->stats.st_mode)) ? 's' : res;
	res = (S_ISFIFO(dir->stats.st_mode)) ? 'p' : res;
	return (res);
}

void			populate_permissions(char permissions[11], t_files *dir)
{
	permissions[0] = get_file_mode(dir);
	permissions[1] = (dir->stats.st_mode & S_IRUSR) ? 'r' : '-';
	permissions[2] = (dir->stats.st_mode & S_IWUSR) ? 'w' : '-';
	if (dir->stats.st_mode & S_ISUID)
		permissions[3] = (dir->stats.st_mode & S_IXUSR) ? 's' : 'S';
	else
		permissions[3] = (dir->stats.st_mode & S_IXUSR) ? 'x' : '-';
	permissions[4] = (dir->stats.st_mode & S_IRGRP) ? 'r' : '-';
	permissions[5] = (dir->stats.st_mode & S_IWGRP) ? 'w' : '-';
	if (dir->stats.st_mode & S_ISGID)
		permissions[6] = (dir->stats.st_mode & S_IXGRP) ? 's' : 'S';
	else
		permissions[6] = (dir->stats.st_mode & S_IXGRP) ? 'x' : '-';
	permissions[7] = (dir->stats.st_mode & S_IROTH) ? 'r' : '-';
	permissions[8] = (dir->stats.st_mode & S_IWOTH) ? 'w' : '-';
	if (dir->stats.st_mode & S_ISVTX)
		permissions[9] = (dir->stats.st_mode & S_IXOTH) ? 't' : 'T';
	else
		permissions[9] = (dir->stats.st_mode & S_IXOTH) ? 'x' : '-';
	permissions[10] = 0;
}

int				transfer_numbers(char **res, int i, int field_width)
{
	char		*tmp;
	int			tmp_i;

	tmp = ft_itoa(field_width);
	tmp_i = -1;
	while (tmp[++tmp_i])
	{
		(*res)[i] = tmp[tmp_i];
		i++;
	}
	ft_memdel((void**)&tmp);
	return (i);
}

char			*get_format_string(int field_widths[5])
{
	int			i;
	char		*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * 42);
	ft_memcpy((void*)res, (const void *)"%s  %", 5);
	i += 5;
	i = transfer_numbers(&res, i, field_widths[HARD_LINKS]);
	ft_memcpy((void*)(res + i), (const void *)"u %-", 4);
	i += 4;
	i = transfer_numbers(&res, i, field_widths[USER]);
	ft_memcpy((void*)(res + i), (const void *)"s  %-", 5);
	i += 5;
	i = transfer_numbers(&res, i, field_widths[GROUP]);
	ft_memcpy((void *)(res + i), (const void *)"s  %", 4);
	i += 4;
	i = transfer_numbers(&res, i, field_widths[SIZE]);
	ft_memcpy((void*)(res + i), (const void *)"lu %s %s", 9);
	return (res);
}
