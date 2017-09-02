/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:29:52 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/10 16:01:12 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			*get_name_from_path(char *path_name)
{
	char			*res;
	int				letter;

	letter = 0;
	while (path_name[letter])
		letter++;
	path_name[letter - 1] == '/' ? (letter -= 2) : (letter -= 1);
	while (path_name[letter] != '/' && letter >= 0)
		letter--;
	res = ft_strdup(path_name + letter + 1);
	letter = 0;
	while (res[letter])
		letter++;
	res[letter - 1] == '/' ? (res[letter - 1] = 0) : 0;
	return (res);
}

static t_files		*new_files_node(void)
{
	t_files			*new;

	new = (t_files *)ft_memalloc(sizeof(t_files));
	new->next = 0;
	new->path = 0;
	new->prev = 0;
	new->contained = 0;
	new->name = 0;
	new->files = 0;
	return (new);
}

t_files				*append_file(char *path_name,
								struct stat st,
								t_files *old_head)
{
	t_files			*current;
	t_files			*head;

	head = old_head;
	if (old_head)
	{
		current = head;
		while (current->next)
			current = current->next;
		current->next = new_files_node();
		current->next->path = ft_strdup(path_name);
		current->next->stats = st;
		current->next->name = get_name_from_path(path_name);
		current->next->prev = current;
	}
	else
	{
		head = new_files_node();
		head->name = get_name_from_path(path_name);
		head->path = ft_strdup(path_name);
		head->stats = st;
	}
	return (head);
}

void				free_files_list(t_files *head, bool free_all)
{
	t_files			*tmp;

	tmp = head;
	while (tmp)
	{
		tmp = head->next;
		if (free_all)
		{
			if (head->name)
				ft_memdel((void**)&(head->name));
			if (head->path)
				ft_memdel((void**)&(head->path));
		}
		ft_memdel((void**)&head);
		head = tmp;
	}
}
