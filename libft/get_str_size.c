/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:19:06 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 15:47:37 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		new_get_str_size(t_modulus *mod, char *tmp_str)
{
	int		str_size;
	int		int_size;

	int_size = ft_strlen(tmp_str);
	int_size = int_size > mod->precision ? int_size : mod->precision;
	if (mod->type == 'p')
		int_size += 2;
	else if (mod->type == 'x' || mod->type == 'X')
		int_size += (mod->flags & POUND) && tmp_str[0] != '0' ? 2 : 0;
	else if (mod->type == 'd' || mod->type == 'i')
		int_size += (mod->flags & PLUS) ||
					(mod->flags & SPACE) ?
					1 : 0;
	str_size = mod->field_width;
	str_size = str_size > mod->precision ? str_size : mod->precision;
	str_size = str_size > int_size ? str_size : int_size;
	return (str_size);
}
