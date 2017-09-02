/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_itoa_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:43:55 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 15:35:06 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** might need to make uimxtoabase imxtoabase?
*/

static char			*check_for_precision(t_modulus *mod, char **res)
{
	if ((mod->type == 'x' || mod->type == 'X' ||
			mod->type == 'u' || mod->type == 'U') &&
			mod->is_precision && mod->precision == 0 && (*res)[0] == '0')
	{
		ft_memdel((void**)res);
		return (ft_strdup(""));
	}
	return (*res);
}

char				*new_get_itoa_shit(va_list *ap, t_modulus *mod, int up)
{
	char			*res;
	int				base;

	base = 10;
	base = mod->type == 'o' || mod->type == 'O' ? 8 : base;
	base = mod->type == 'x' || mod->type == 'X' ? 16 : base;
	if (!mod->length_modifier)
		res = ft_uitoabase((int)va_arg(*ap, unsigned int), base, up);
	else if (mod->length_modifier == L)
		res = ft_uimxtoabase(va_arg(*ap, unsigned long), base, up);
	else if (mod->length_modifier == LL)
		res = ft_uimxtoabase(va_arg(*ap, unsigned long long), base, up);
	else if (mod->length_modifier == H)
		res = ft_uimxtoabase((unsigned short)va_arg(*ap, int), base, up);
	else if (mod->length_modifier == HH)
		res = ft_uimxtoabase((unsigned char)va_arg(*ap, int), base, up);
	else if (mod->length_modifier == J)
		res = ft_uimxtoabase(va_arg(*ap, uintmax_t), base, up);
	else if (mod->length_modifier == Z)
		res = ft_sttoabase(va_arg(*ap, size_t), base, up);
	else
		return (ft_strdup("0"));
	return (check_for_precision(mod, &res));
}
