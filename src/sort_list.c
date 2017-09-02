/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:51:17 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/09 16:45:54 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_files	*reverse_list(t_files *old_head)
{
	t_files		*res;
	t_files		*tmp_head;
	t_files		*tmp_res;

	res = ft_memdup(old_head, sizeof(*old_head));
	res->next = 0;
	tmp_head = old_head;
	old_head = old_head->next;
	while (old_head)
	{
		tmp_res = ft_memdup(old_head, sizeof(*old_head));
		tmp_res->next = res;
		res = tmp_res;
		old_head = old_head->next;
	}
	free_files_list(tmp_head, false);
	return (res);
}

void			swap_node(t_files **previous, t_files **current,
							t_files **next, t_files **head)
{
	t_files		*tmp;

	if (*previous)
	{
		tmp = (*next)->next;
		(*previous)->next = *next;
		(*next)->next = *current;
		(*current)->next = tmp;
	}
	else
	{
		tmp = (*next)->next;
		(*next)->next = *current;
		(*current)->next = tmp;
		*head = *next;
	}
	tmp = *next;
	*next = *current;
	*current = tmp;
}

t_files			*bubble_sort(t_files *head, int list_len, unsigned int flags)
{
	int			iterations;
	t_files		*current;
	t_files		*previous;
	t_files		*next;

	iterations = 0;
	while (iterations <= list_len)
	{
		current = head;
		previous = 0;
		next = current->next;
		while (next)
		{
			if ((flags & LOW_T) ?
				!by_time(current, next) : !alphabetical(current, next))
				swap_node(&previous, &current, &next, &head);
			previous = current;
			current = current->next;
			next = next->next;
		}
		iterations++;
	}
	if (flags & LOW_R)
		head = reverse_list(head);
	return (head);
}

t_files			*sort_list(t_files *head, unsigned int flags)
{
	int			list_len;
	t_files		*tmp;

	list_len = 0;
	tmp = head;
	while (tmp && (list_len += 1))
		tmp = tmp->next;
	head = bubble_sort(head, list_len, flags);
	return (head);
}
