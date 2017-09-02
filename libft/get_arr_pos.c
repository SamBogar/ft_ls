/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:17:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 15:08:21 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			new_get_arr_pos(t_modulus *mod, int str_size, char *tmp_str)
{
	int		int_size;
	int		digits;

	digits = ft_strlen(tmp_str);
	if (((mod->flags & ZERO) && (mod->precision > digits)))
		return (str_size - mod->precision - 1);
	else if (((mod->flags & ZERO) && !mod->is_precision))
		return (0);
	else
	{
		int_size = digits;
		int_size = int_size > mod->precision ? int_size : mod->precision;
	}
	return (str_size - int_size);
}
