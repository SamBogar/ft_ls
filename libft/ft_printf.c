/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 19:11:15 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/17 15:45:35 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				substrlen(const char *format)
{
	int			res;

	res = 0;
	while (format[res] != '%' && format[res])
		res++;
	return (res);
}

static int		print_mod(const char *format, int *i, va_list *ap)
{
	int			res;
	t_modulus	*mod;

	mod = define_modulus(format + *i + 1, ap);
	res = 0;
	if ((mod)->result)
	{
		ft_putstr(mod->result);
		if (mod->char_is_null)
			write(1, "", 1);
		res += (int)ft_strlen((mod)->result);
	}
	else
		(*i)++;
	ft_memdel((void**)&mod->result);
	*i += (mod)->cs_width;
	if ((mod)->char_is_null)
		res++;
	ft_memdel((void**)&mod);
	return (res);
}

static int		print_str(const char *format, int *i)
{
	int			diff;

	diff = *i;
	*i += substrlen(format + *i);
	write(1, format + diff, *i - diff);
	return (*i - diff);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			res;

	va_start(ap, format);
	i = 0;
	res = 0;
	while (i < (int)ft_strlen(format))
	{
		if (format[i] == '%')
		{
			res += print_mod(format, &i, &ap);
			if (!format[i])
				break ;
		}
		else
			res += print_str(format, &i);
	}
	va_end(ap);
	return (res);
}
