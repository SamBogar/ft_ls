/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 14:46:20 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/03 20:21:05 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			get_which_flag(char letter)
{
	if (letter == 'l')
		return (LOW_L);
	else if (letter == 'R')
		return (CAP_R);
	else if (letter == 'a')
		return (LOW_A);
	else if (letter == 'r')
		return (LOW_R);
	else if (letter == 't')
		return (LOW_T);
	else
		return (ILLEGAL_OPTION);
}

int			parse_flags(int ac, char **av, unsigned int *flags)
{
	int		arg_num;
	int		letter;

	arg_num = 0;
	while (++arg_num < ac)
		if (av[arg_num][0] == '-' && av[arg_num][1])
		{
			letter = 0;
			while (av[arg_num][++letter])
			{
				*flags |= get_which_flag(av[arg_num][letter]);
				if ((*flags & ILLEGAL_OPTION))
					return (av[arg_num][letter] * -1);
			}
		}
		else
			return (arg_num);
	return (arg_num);
}

int			populate_struct(int ac, char **av, t_env *env)
{
	int		last_or_invalid_flag;

	env->flags = 0;
	last_or_invalid_flag = parse_flags(ac, av, &env->flags);
	if (last_or_invalid_flag >= 0)
		get_files(env, last_or_invalid_flag, ac, av);
	return (last_or_invalid_flag);
}
