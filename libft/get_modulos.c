/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modulos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:58:32 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 14:26:57 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			instantiate_modulus(t_modulus **res)
{
	(*res)->arg_num = 0;
	(*res)->pos = 0;
	(*res)->type = 0;
	(*res)->flags = 0;
	(*res)->field_width = 0;
	(*res)->precision = 0;
	(*res)->is_precision = 0;
	(*res)->length_modifier = 0;
	(*res)->char_is_null = 0;
	(*res)->result = 0;
}

t_modulus		*define_modulus(const char *format, va_list *ap)
{
	t_modulus	*res;
	int			i;
	int			prev_i;

	i = 0;
	res = (t_modulus *)ft_memalloc(sizeof(t_modulus));
	instantiate_modulus(&res);
	while (format[i] && res->type == 0)
	{
		prev_i = i;
		i += get_flags(format + i, &res);
		i += get_width_specifier(format + i, &res);
		while (get_precision(format + i, &res))
			i += get_precision(format + i, &res);
		i += get_length(format + i, &res, res->length_modifier);
		i += get_type(format + i, &res);
		if (i == prev_i)
			res->type = format[i++];
	}
	res->cs_width = i + 1;
	resolve(ap, res);
	return (res);
}

int				get_modulus_count(const char *format)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			res++;
		i++;
	}
	return (res);
}

t_modulus		**get_modulos(const char *format)
{
	int			i;
	int			j;
	int			mod_count;
	t_modulus	**mods;

	j = 0;
	i = 0;
	mod_count = get_modulus_count(format);
	mods = (t_modulus **)malloc(sizeof(t_modulus *) * (mod_count + 1));
	ft_bzero(mods, sizeof(mods) + 1);
	mods[mod_count + 1] = 0;
	while (i < (int)ft_strlen(format))
	{
		if (format[i] == '%')
		{
			i += (mods[j])->cs_width;
			j++;
		}
		else
			i++;
	}
	return (mods);
}
