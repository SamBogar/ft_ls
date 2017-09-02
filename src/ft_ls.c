/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:24:26 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/08 16:01:43 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			main(int ac, char **av)
{
	t_env	*env;
	int		last_flag_arg;

	env = (t_env*)ft_memalloc(sizeof(t_env));
	last_flag_arg = populate_struct(ac, av, env);
	if (last_flag_arg < 0)
		ft_printf("ls: illegal option -- %c\n%s\n",
					(char)(last_flag_arg * -1),
					"usage: ./ft_ls [-Rlart] [file ...]");
	else
		print_out_list(env);
	return (0);
}
