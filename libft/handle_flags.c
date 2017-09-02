/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:29:09 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 15:54:38 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			new_handle_flags(t_modulus *mod, int str_size, char *tmp_str)
{
	int		i;
	int		is_hyphen;

	i = 0;
	is_hyphen = (mod->flags & HYPHEN);
	if (is_hyphen)
		i = mod->is_precision && mod->precision > (int)ft_strlen(tmp_str) ?
			mod->precision - ft_strlen(tmp_str) + i : i;
	else
		i = str_size - ft_strlen(tmp_str);
	return (i);
}
